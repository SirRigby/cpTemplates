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
    vector<int> sz;

    DSU(int n1 ){
        n=n1;
        v.resize(n);
        sz.resize(n);
        make();
    }

    void make(){
        for(int i=0;i<n;i++){
            v[i]=i;
            sz[i]=1;
        }
    }

    int find(int i){
        if(i==v[i]){
            return i;
        }
        return v[i]=find(v[i]);
    }

    bool unio(int i, int j){
        i=find(i);
        j=find(j);
        if(i==j){return 0;}
        if(sz[i]<sz[j]){
            swap(i,j);
        }
        sz[i]+=sz[j];
        v[j]=i;
        return 1;
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    pair<long long,pair<int,int>> v[m];
    DSU dsu(n);
    for(int i=0;i<m;i++){
        int x,y;long long c;
        cin>>x>>y>>c;x--;y--;
        v[i]={c,{x,y}};
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