#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
struct DSU{

    int n;
    vector<int> v;
    vector<int> rnk;
    stack<pair<pair<int,int>,pair<int,int>>> op;
    
    DSU(int n1 ){
        n=n1;
        v.resize(n);
        rnk.resize(n);
        make();
    }

    void make(){
        for(int i=0;i<n;i++){
            v[i]=i;
            rnk[i]=0;
        }
    }

    int find(int i){
        if(i==v[i]){
            return i;
        }
        return find(v[i]);
    }

    bool unio(int i, int j){
        i=find(i);
        j=find(j);
        if(i==j){return 0;}
        if(rnk[i]<rnk[j]){
            swap(i,j);
        }
        op.push({{i,rnk[i]},{j,rnk[j]}});
        if(rnk[i]==rnk[j]){
            rnk[i]++;
        }
        v[j]=i;
        return 1;
    }

    void rollback(){
        if(op.empty()){
            return;
        }
        auto p=op.top();
        op.pop();
        v[p.first.first]=p.first.first;
        v[p.second.first]=p.second.first;
        rnk[p.first.first]=p.first.second;
        rnk[p.second.first]=p.second.second;
    }

};

int main(){
    
    return 0;  
}