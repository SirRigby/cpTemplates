#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

typedef long long tds;
void bell(int root,int n, vector<pair<int,tds>> adj[]){
    //
    tds INF=INT64_MAX;
    //
    vector<tds> dist(n,INF);
    dist[root]=0;
    vector<pair<tds,pair<int,int>>> edges;
    for(int i=0;i<n;i++){
        for(auto j:adj[i]){
            edges.push_back({j.second,{i,j.first}});
        }
    }
    for(int i=0;i<n-1;i++){
        for(auto e:edges){
            if(dist[e.second.first]!=INF){
                if(dist[e.second.second]>dist[e.second.first]+e.first){
                    dist[e.second.second]=dist[e.second.first]+e.first;
                }
            }
        }
    }
    bool isneg=0;
    for(auto e:edges){
        if(dist[e.second.first]!=INF){
            if(dist[e.second.second]>dist[e.second.first]+e.first){
                dist[e.second.second]=dist[e.second.first]+e.first;
                isneg=1;
                break;
            }
        }
    }
}

typedef long long tds;
void spfa(int root,int n, vector<pair<int,tds>> adj[]){
    //
    tds INF=INT64_MAX;
    //
    vector<tds> dist(n,INF);
    int cnt[n];
    memset(cnt,0,sizeof(cnt));
    bool inqueue[n];
    memset(inqueue,0,sizeof(inqueue));
    queue<int> qu;
    qu.push(root);
    dist[root]=0;
    inqueue[root]=1;
    bool isneg=0;
    while(!qu.empty() && !isneg){
        int node=qu.front();
        qu.pop();
        inqueue[node]=0;
        for(auto i: adj[node]){
            int j=i.first;
            tds wt=i.second;
            if(wt!=INF && dist[j]>wt+dist[node]){
                dist[j]=wt+dist[node];
                if(!inqueue[j]){
                    qu.push(j);
                    inqueue[j]=1;
                    cnt[j]=1+cnt[node];
                    if(cnt[j]>n){
                        isneg=1;
                        break;
                    }
                }
            }
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