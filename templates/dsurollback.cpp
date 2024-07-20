#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    pair<long long,pair<int,int>> v[m];
    vector<vector<int>> edges;
    DSU dsu(n);
    //
    for(int i=0;i<m;i++){
        int x,y;long long c;
        cin>>x>>y>>c;x--;y--;
        v[i]={c,{x,y}};
    }
    //

    {
    vector<pair<int,pair<int,int>>> v; 
    for(int i=0;i<edges.size();i++){
        v.push_back({edges[i][2],{edges[i][0],edges[i][1]}});
        v.push_back({edges[i][2],{edges[i][0],edges[i][1]}});
    }
    }

    sort(v,v+m);
    long long h=0;
    int yy=n;
    for(int i=0;i<m;i++){
        long long c;int x,y;
        c=v[i].first;
        x=v[i].second.first;
        y=v[i].second.second;
        if(!dsu.unio(x,y)){
            continue;
        }
        h+=c;
        yy--;
    }
    if(yy!=1){
        cout<<"IMPOSSIBLE";return 0;
    }
    cout<<h;
    return 0;  
}