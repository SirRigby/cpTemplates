#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

void bfs(vector<int> adj[], vector<bool> & vis){

    queue<int> qu;
    qu.push(0);
    vis[0]=1;

    while(!qu.empty()){
        int par=qu.front();
        for(auto i: adj[par]){
            if(vis[i]){
                continue;
            }
            vis[i]=1;
            qu.push(i);
        }
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

        pair<int,int> i;
        int w1[]={1,0,0,-1};
        int w2[]={0,1,-1,0};
        int k,m;

        {

            int x=i.first+w1[k],y=i.second+w2[k];
            if(x>=0 && y>=0 && x<n && y<m){

            }
        }
        
    }
    return 0;
}