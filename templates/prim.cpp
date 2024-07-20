#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

typedef long long tds;
void prim(int n, vector<pair<int,tds>> adj[]){
    int par[n];
    memset(par,-1,sizeof(par));
    bool vis[n];
    memset(vis,0,sizeof(vis));
    tds dist[n];
    set<pair<tds,int>> pq;
    dist[0]=0;
    pq.insert({0,0});
    for(int i=0;i<n;i++){
        pair<tds,int> top=*pq.begin();
        pq.erase(pq.begin());
        int node=top.second;
        vis[node]=1;
        for(auto j:adj[node]){
            int child=j.first;
            tds wt=j.second;
            if(vis[child]==0 && (par[child]==-1 || dist[child]>wt)){
                if(par[child]!=-1){
                    pq.erase({dist[child],child});
                    dist[child]=wt;
                    pq.insert({wt,child});
                    par[child]=node;
                }
            }
        }
    }
    bool isdone=1;
    tds sum=0;
    for(int i=1;i<n;i++){
        if(par[i]==-1){
            isdone=0;
            break;
        }
        else{
            sum+=dist[i];
        }
    }
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