#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

vector<int> kmp(string &s){
    int n=s.size();
    vector<int> pi(n,0);
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        while(j>0 && s[i]!=s[j]){
            j=pi[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        pi[i]=j;
    }
    return pi;
}

int match(string &s, string &t){
    int m=s.size();
    int n=t.size();
    int r=0;

    vector<int> v=kmp(s);
    int j=0,i=0;
    while(i<n){
        if(s[j]==t[i]){
            i++;
            j++;
        }
        if(j==m){
            r++;
            j=v[j-1];
        }
        else if(i<n && s[j]!=t[i]){
            if(j!=0){
                j=v[j-1];
            }
            else{
                i++;
            }
        }
    }
    return r;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        
    }
    return 0;
}