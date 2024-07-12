#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

struct Binlift{

    int n;
    int logn;
    vector<vector<int>> table;
    vector<int> depth;

    int log2(int x){
        return 31 - __builtin_clz(x);
    }

    Binlift(int n1, vector<int> adj[], int root){
        n=n1;
        logn= log2(n);
        depth.resize(n);
        table.resize(n, vector<int> (logn+1,-1));
        build(root,adj);
    }

    void build(int r, vector<int> adj[]){
        dfs(r,adj,-1,0);
        for(int j=1;j<=logn;j++){
            for(int i=0;i<n;i++){
                if(table[i][j-1]!=-1){
                    table[i][j]=table[table[i][j-1]][j-1];
                }
            }
        }
    }

    void dfs(int r, vector<int> adj[], int parent, int height){

        table[r][0]=parent;
        depth[r]=height;

        for(auto i: adj[r]){
            if(i==parent){
                continue;
            }

            dfs(i,adj,r,height+1);
            
        }

    }

    int findkth(int x, int k){
        int p=x;
        for(int i=logn;i>=0;i--){
            if(k&(1<<i)){
                p=table[p][i];
            }
        }
        return p;
    }

    int findlca(int a, int b){
        int x=max(0,depth[a]-depth[b]);
        int y=max(0,depth[b]-depth[a]);
        a=findkth(a,x);
        b=findkth(b,y);
        if(a==b){
            return a;
        }
        int ans=-1;
        for(int i=logn;i>=0;i--){
            if(table[a][i]==table[b][i]){
                ans=table[a][i];
            }
            else{
                a=table[a][i];
                b=table[b][i];
            }
        }
        return ans;
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        
    }
    return 0;
}