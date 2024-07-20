#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

void brdfs(int r, vector<int> adj[], int par, int lo[], int timer[], int & time, vector<pair<int,int>>& bridges){

    timer[r]=time++;
    lo[r]=timer[r];

    for(auto i: adj[r]){

        if(i==par){
            //comment out for directed graphs
            continue;
        }

        if(timer[i]!=-1){
            lo[r]=min(lo[r],timer[i]);
        }

        else{
            brdfs(i,adj,r,lo,timer,time, bridges);
            lo[r]=min(lo[r],lo[i]);
            if(lo[i]>timer[r]){
                bridges.push_back({r,i});
            }
        }

    }

}
vector<pair<int,int>> bridge(int n,vector<int> adj[]){
    int time=0;
    int lo[n],timer[n];
    memset(timer,-1,sizeof(timer));
    vector<pair<int,int>> bridges;
    for(int i=0;i<n;i++){
        if(timer[i]==-1){
            brdfs(i,adj,-1,lo,timer,time,bridges);
        }
    }
    return bridges;
}



void ctdfs(int r, vector<int> adj[], int par, int lo[], int timer[], int & time, vector<int>& cuts){

    timer[r]=time++;
    lo[r]=timer[r];
    int c=0;
    int iscut=0;

    for(auto i: adj[r]){

        if(i==par){
            //comment out for directed graphs
            continue;
        }

        if(timer[i]!=-1){
            lo[r]=min(lo[r],timer[i]);
        }

        else{
            ctdfs(i,adj,par,lo,timer,time, cuts);
            c++;
            lo[r]=min(lo[r],lo[i]);
            if(lo[i]>=timer[r] && par!=-1){
                iscut=1;
            }
        }

    }

    if(par==-1 && c>1){
        iscut=1;
    }

    if(iscut){
        cuts.push_back(r);
    }

}
vector<int> cutvrt(int n,vector<int> adj[]){
    int time=0;
    int lo[n],timer[n];
    memset(timer,-1,sizeof(timer));
    vector<int> cuts;
    for(int i=0;i<n;i++){
        if(timer[i]==-1){
            ctdfs(i,adj,-1,lo,timer,time,cuts);
        }
    }
    return cuts;
}

void condfs(int r, vector<int> adj[], int par, int lo[], int timer[], int & time, vector<vector<int>>& components, stack<int>& track, bool isdone[]){

    timer[r]=time++;
    lo[r]=timer[r];
    track.push(r);
    isdone[r]=1;
    for(auto i: adj[r]){

        if(i==par){
            //comment out for directed graphs
            continue;
        }

        if(timer[i]==-1){
            condfs(i,adj,r,lo,timer,time, components, track, isdone);
            lo[r]=min(lo[r],lo[i]);
        }

        else if(isdone[i]){
            lo[r]=min(lo[r],timer[i]);
        }

    }

    if(lo[r]==timer[r]){
        vector<int> component;
        while(track.top()!=r){
            int node=track.top();
            component.push_back(node);
            track.pop();
            isdone[node]=0;
        }
        track.pop();
        component.push_back(r);
        isdone[r]=0;
        components.push_back(component);
    }

}
void condgraph(int n,vector<int> adj[]){
    int time=0;
    int lo[n],timer[n];
    bool isdone[n];
    memset(isdone,0,sizeof(isdone));
    memset(timer,-1,sizeof(timer));
    int roots[n];
    int ncon=0;
    vector<vector<int>> components;
    for(int i=0;i<n;i++){
        if(timer[i]!=-1){
            continue;
        }
        stack<int> track;
        condfs(i,adj,-1,lo,timer,time,components,track,isdone);
    }
    for(auto i:components){
        for(auto j:i){
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
            adj[edges[i][1]-iszero].push_back(edges[i][0]-iszero);
        }

        }

        {

        int iszero=1;
        vector<int> adj[n];
        for(int i=0;i<m;i++){
            int x,y;cin>>x>>y;
            adj[x-iszero].push_back(y-iszero);
            adj[y-iszero].push_back(x-iszero);
        }

        }

    }
    return 0;
}