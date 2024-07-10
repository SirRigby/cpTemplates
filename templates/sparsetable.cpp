#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

struct Sparse{

    typedef long long td;
    static const td identity=0;

    struct Node{

        td val;

        Node(){
            val=identity;
        }

        Node(td val1){
            val=val1;
        }

        void merge(Node &n1, Node &n2){
            val=n1.val + n2.val;
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
            table[i][0]=v[i];
        }
        for(int i=1;i<=logn;i++){
            for(int j=0;j+(1<<i)<=n;j++){
                table[j][i].merge(table[j][i-1],table[j+(1<<(i-1))][i-1]);
            }
        }
    }

    td query(int left, int right){
        if(left>right){
            return identity;
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
        return ans.val;
    }

    td queryf(int left,int right){
        if(left>right){
            return identity;
        }
        left=max(0,left);
        right=min(n-1,right);
        Node ans=Node();
        int j=log2(right-left+1);
        ans.merge(table[left][j],table[right-(1<<j)+1][j]);

        return ans.val;
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