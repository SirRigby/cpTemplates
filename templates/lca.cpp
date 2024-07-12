#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

struct Sparse{

    typedef int td;
    static const td identity=INT_MAX;

    struct Node{

        td val;
        td index;
        Node(){
            val=identity;
            index=-1;
        }

        Node(td val1, int ind){
            val=val1;
            index=ind;
        }

        void merge(Node &n1, Node &n2){
            if(n1.val<=n2.val){
                val=n1.val;
                index=n1.index;
            }
            else{
                val=n2.val;
                index=n2.index;
            }
        }

    };

    int n;
    vector<vector<Node>> table;
    vector<td> v;
    int logn;

    int log2(int x){
        return 31 - __builtin_clz(x);
    }

    Sparse(int n1, vector<td>& arr){
        n=n1;
        v=arr;
        logn=log2(n);
        table.resize(n1,vector<Node> (logn+1,Node()));
        build();
    }

    void build(){
        for(int i=0;i<n;i++){
            table[i][0]=Node(v[i],i);
        }
        for(int i=1;i<=logn;i++){
            for(int j=0;j+(1<<i)<=n;j++){
                table[j][i].merge(table[j][i-1],table[j+(1<<(i-1))][i-1]);
            }
        }
    }

    Node query(int left, int right){
        if(left>right){
            return Node();
        }
        left=max(0,left);
        right=min(n-1,right);
        Node ans=Node();
        for(int j=log2(right-left+1);j>=0;j--){
            if((1<<j)<=right-left+1){
                ans.merge(ans,table[left][j]);
                left+=(1<<j);
            }
        }
        return ans;
    }

    Node queryf(int left,int right){
        if(left>right){
            return Node();
        }
        left=max(0,left);
        right=min(n-1,right);
        Node ans=Node();
        int j=log2(right-left+1);
        ans.merge(table[left][j],table[right-(1<<j)+1][j]);

        return ans;
    }

};

struct Lca{

    int n;
    vector<int> eulertour, index, node;
    Sparse table=Sparse(0,eulertour);

    Lca(int n1, vector<int> adj[], int root){
        n=n1;
        index.resize(n);
        dfs(root,adj,-1,0);
        table=Sparse(eulertour.size(),eulertour);
    }

    void dfs(int r, vector<int> adj[], int parent, int height){

        eulertour.push_back(height);
        node.push_back(r);
        index[r]=node.size()-1;

        for(auto i: adj[r]){
            if(i==parent){
                continue;
            }
            
            dfs(i,adj,r,height+1);
            eulertour.push_back(height);
            node.push_back(r);
        }

    }

    int que(int a, int b){
        return node[table.queryf((index[a],index[b]),max(index[a],index[b])).index];
    }

    int depth(int a){
        return eulertour[index[a]];
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