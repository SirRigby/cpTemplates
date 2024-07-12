#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

void dfs(int r, vector<int> adj[], int parent){

    for(auto i: adj[r]){
        if(i==parent){
            continue;
        }
        
        dfs(i,adj,r);

    }

}

void dfs(int r, vector<int> adj[], vector<bool> & vis){

    vis[r]=1;

    for(auto i: adj[r]){
        if(vis[i]){
            continue;
        }
        
        dfs(i,adj,vis);

    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){

        int n;
        vector<vector<int>> edges;

        {

        int iszero=1;
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]-iszero].push_back(edges[i][1]-iszero);
            adj[edges[i][1]-iszero].push_back(edges[i][0]-iszero);
        }

        }

        {

        int iszero=1;
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            int x,y;cin>>x>>y;
            adj[x-iszero].push_back(y-iszero);
            adj[y-iszero].push_back(x-iszero);
        }

        }

        
    }
    return 0;
}