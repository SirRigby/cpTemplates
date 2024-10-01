#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout); freopen("error.txt","w", stderr) ;
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

vector<int> zAlgo(string &s){
    int l=0,r=0;
    int n=s.size();
    vector<int> v(s.size());
    for(int i=1;i<n;i++){
        if(i<r){
            v[i]=min(r-i,v[i-l]);
        }
        while(i+v[i]<n && s[v[i]]==s[i+v[i]]){
            v[i]++;
        }
        if(r<v[i]+i){
            l=i;
            r=i+v[i];
        }
    }
    return v;
}

int main(){
    return 0;
}