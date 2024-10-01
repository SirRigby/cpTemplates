#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout); freopen("error.txt","w", stderr) ;
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

struct DSU{

    int n;
    vector<int> v;
    vector<int> rnk;
    // vector<int> sz;
    stack<pair<pair<int,int>,pair<int,int>>> op;
    
    DSU(int n1 ){
        n=n1;
        v.resize(n);
        rnk.resize(n);
        // sz.resize(n);
        make();
    }

    void make(){
        for(int i=0;i<n;i++){
            v[i]=i;
            rnk[i]=0;
            // sz[i]=1;
        }
    }

    int find(int i){
        if(i==v[i]){
            return i;
        }
        return find(v[i]);
    }

    bool unio(int i, int j){
        i=find(i);
        j=find(j);
        if(i==j){return 0;}
        if(rnk[i]<rnk[j]){
            swap(i,j);
        }
        op.push({{i,rnk[i]},{j,rnk[j]}});
        if(rnk[i]==rnk[j]){
            rnk[i]++;
        }
        v[j]=i;
        // sz[i]+=sz[j];
        return 1;
    }

    void rollback(){
        if(op.empty()){
            return;
        }
        auto p=op.top();
        op.pop();
        v[p.first.first]=p.first.first;
        v[p.second.first]=p.second.first;
        rnk[p.first.first]=p.first.second;
        rnk[p.second.first]=p.second.second;
        // sz[p.first.first]=sz[p.second.first];
    }

};

struct DynamicCon{
    static const int MAXN=2e5;
    vector<pair<int,int>> segtree[4*MAXN];
    int time=0;

    void update(int start, int end, int index, int left, int right, pair<int,int> edge){
        if(start>right || end<left){
            return;
        }
        if(start>=left && end<=right){
            segtree[index].push_back(edge);
            return;
        }
        int mid=(start+end)/2;
        update(start,mid,index<<1,left,right,edge);
        update(mid+1,end,(index<<1)|1,left,right,edge);
    }

    void dfs(int start, int end, int index, DSU &dsu){
        int cnt=0;
        for(auto &i:segtree[index]){
            if(dsu.unio(i.first,i.second)){
                cnt++;
            }
        }
        if(start==end){
            // start=0 => default
            // q[start-1]=> start

        }
        else{
            int mid=(start+end)/2;
            dfs(start,mid,index<<1,dsu);
            dfs(mid+1,end,(index<<1)|1,dsu);
        }
        for(int i=0;i<cnt;i++){
            dsu.rollback();
        }
    }
};

 
int main(){
    int n,q;
    cin>>n>>q;
    DSU dsu(n);
    DynamicCon tree;
    int m;cin>>m;
    map<pair<int,int>,int> mp;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        if(x>y){
            mp[{x,y}]=tree.time;
        }
        else{
            mp[{y,x}]=tree.time;
        }
    }
    for(int i=0;i<q;i++){
        int t;
        cin>>t;
        //0=>add,1=>del,2=>que
        if(t<=1){
            int x,y;
            cin>>x>>y;
            x--;y--;
            if(y>x){
                swap(x,y);
            }
            auto it=mp.find({x,y});
            if(t==0){
                if(it==mp.end()){
                    mp[{x,y}]=tree.time+1;
                }
            }
            if(t==1){
                if(it!=mp.end()){
                    tree.update(0,q,1,mp[{x,y}],tree.time,{x,y});
                    mp.erase(it);
                }
            }
        }
        else{
            tree.time++;
        }
    }
    for(auto &i:mp){
        tree.update(0,q,1,i.second,tree.time,i.first);
    }
    return 0;
}