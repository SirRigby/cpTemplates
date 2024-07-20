#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

typedef long long tds;
vector<tds> djikstra(int root,int n, vector<pair<int,tds>> adj[]){
    vector<tds> dist(n,-1);
    dist[root]=0;
    set<pair<tds,int>> pq;
    pq.insert({0,root});
    while(!pq.empty()){
        auto key=(*pq.begin());
        pq.erase(pq.begin());
        tds distance=key.first;
        int node=key.second;
        for(auto i: adj[node]){
            int child=i.first;
            tds wt=i.second;
            if(dist[child]==-1 || dist[child]>wt+distance){
                if(dist[child]!=-1){
                    pq.erase({dist[child],child});
                }
                dist[child]=distance+wt;
                pq.insert({dist[child],child});
            }
        }
    }
    return dist;
}

int main(){

    vector<vector<int>> edges;

    int n,m;

    {

    int iszero=1;
    vector<pair<int,int>> adj[n];
    for(auto i:edges){
        i[0]-=iszero;
        i[1]-=iszero;
        adj[i[0]].push_back({i[1],i[2]});
        adj[i[1]].push_back({i[0],i[2]});
    }

    }

    {

    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        x--;y--;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }

    }

    return 0;
}