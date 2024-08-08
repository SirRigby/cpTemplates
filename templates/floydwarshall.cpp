#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

typedef long long tds;
void floydw(int n, vector<pair<int,tds>> adj[]){
    //
    tds INF=INT64_MAX;
    //
    vector<vector<tds>> dist(n,vector<tds> (n,INF));
    for(int i=0;i<n;i++){
        dist[i][i]=0;
    }
    for(int i=0;i<n;i++){
        for(auto j: adj[i]){
            dist[i][j.first]=min(dist[i][j.first],j.second);
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]<INF && dist[k][j]<INF){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
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