#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

void toposort(int r, vector<int> adj[], bool vis[], vector<int> &v){
    vis[r]=1;
    for(auto i: adj[r]){
        if(vis[i]){
            continue;
        }
        toposort(i,adj,vis,v);
    }
    v.push_back(r);
}
vector<int> topo(int n, vector<int> adj[]){
    vector<int> v;
    if(n==0){
        return v;
    }
    bool vis[n];
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
        if(!vis[i]){
            toposort(i,adj,vis,v);
        }
    }
    reverse(v.begin(),v.end());
    return v;
}

bool topocycle(int r, vector<int> adj[], bool vis[], bool vit[], vector<int> &v){
    vis[r]=1;
    vit[r]=1;
    for(auto i: adj[r]){
        if(!vis[i]){
            if(topocycle(i,adj,vis,vit,v)){
                return 1;
            }
        }
        if(vit[i]){
            return 1;
        }
    }
    v.push_back(r);
    vit[r]=0;
    return 0;
}
vector<int> topoc(int n, vector<int> adj[]){
    vector<int> v;
    if(n==0){
        return v;
    }
    bool vis[n],vit[n];
    memset(vis,0,sizeof(vis));
    memset(vit,0,sizeof(vit));
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(topocycle(i,adj,vis,vit,v)){
                v.clear();
                return v;
            }
        }
    }
    reverse(v.begin(),v.end());
    return v;
}

int main(){
    
    int n;
    vector<vector<int>> edges;

    {

    int iszero=1;
    vector<int> adj[n];
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]-iszero].push_back(edges[i][1]-iszero);
    }

    }

    return 0;
}