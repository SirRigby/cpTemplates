#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

long long binpow(long long x, long long y, long long M){
    long long r=1;
    long long z=x%M;
    while(y){
        if(y&1){
            r=(r*z)%M;
        }
        z=(z*z)%M;
        y>>=1;
    }
    return r;
}

const int MAXF=1000001;
int M=1e9+7;

int fact[MAXF];
int factinv[MAXF];

void pnc(){
    fact[0]=1;
    for(int i=1;i<MAXF;i++){
        fact[i]=(fact[i-1]*1LL*i)%M;
    }
    factinv[MAXF-1]=binpow(fact[MAXF-1],M-2,M);
    for(int i=MAXF-2;i>=0;i--){
        factinv[i]=(factinv[i+1]*1LL*(i+1))%M;
    }
}

int comb(int a, int b){
    if(a<=b){
        return a==b;
    }
    return (((fact[a]*1LL*factinv[a-b])%M)*factinv[b])%M;
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