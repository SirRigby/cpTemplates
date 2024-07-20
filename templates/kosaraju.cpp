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
void kosaraju(int n, vector<int> adj[]){
    vector<int> adjc[n];
    for(int i=0;i<n;i++){
        for(auto j: adj[i]){
            adjc[j].push_back(i);
        }
    }
    bool vis[n];
    memset(vis,0,sizeof(vis));
    vector<int> order;
    for(int i=0;i<n;i++){
        if(vis[i]){
            continue;
        }
        toposort(i,adj,vis,order);
    }
    memset(vis,0,sizeof(vis));
    int roots[n]; //index of component
    memset(roots,0,sizeof(roots));
    vector<vector<int>> components;
    int ncon=0;
    for(int i=n-1;i>=0;i--){
        if(vis[order[i]]){
            continue;
        }
        vector<int> component;
        toposort(order[i],adjc,vis,component);
        components.push_back(component);
        for( auto j :component){
            roots[j]=ncon;
        }
        ncon++;
    }
    vector<int> adjcon[ncon];
    for(int i=0;i<n;i++){
        for(auto j: adj[i]){
            if(roots[i]!=roots[j]){
                adjcon[roots[i]].push_back(roots[j]);
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        vector<vector<int>> edges;

        {

        int iszero=1;
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]-iszero].push_back(edges[i][1]-iszero);
        }

        }

        {

        int iszero=1;
        vector<int> adj[n];
        for(int i=0;i<m;i++){
            int x,y;cin>>x>>y;
            adj[x-iszero].push_back(y-iszero);
        }

        }
    }
    return 0;
}