#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

void kahn(vector<int> adj[], int n, vector<int>& v){

    queue<int> qu;

    int in[n];
    memset(in,0,sizeof(in));

    for(int i=0;i<n;i++){
        for(auto j: adj[i]){
            in[j]++;
        }
    }

    for(int i=0;i<n;i++){
        if(in[i]==0){
            qu.push(i);
        }
    }

    while(!qu.empty()){
        int par=qu.front();
        v.push_back(par);
        qu.pop();
        for(auto i: adj[par]){
            in[i]--;
            if(in[i]==0){
                qu.push(i);
            }
        }
    }

    if(v.size()!=n){
        v.clear();
    }

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