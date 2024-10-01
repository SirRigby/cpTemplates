#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout); freopen("error.txt","w", stderr) ;
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

// v contains substring length
vector<int> manacher(string &t){
    string s;
    for(auto i:t){
        s.push_back('#');
        s.push_back(i);
    }
    s.push_back('#');
    vector<int> v(s.size(),0);
    int l=1,r=1;
    for(int i=1;i<s.size();i++){
        if(i>r){
            l=i,r=i;
        }
        v[i]=min(r-i,v[l+r-i]);
        while(i>=v[i]+1 && i+v[i]+1<s.size() && s[i-v[i]-1]==s[i+v[i]+1]){
            v[i]++;
        }
        if(i+v[i]>r){
            l=i-v[i];
            r=i+v[i];
        }
    }
    return v;
}

int main(){
    
    return 0;
}