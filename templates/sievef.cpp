#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

static const int MSV=1e3;
int primes[MSV/2];
void sieve(int MS=MSV ){
    //num=3+2i
    for(int i=0;(3+2*i)*(3+2*i)<=(MS);i++){
        int u=3+2*i;
        if(primes[i]==0){
            for(int j=(u*u-3)/2;j<MS/2;j+=u){
                primes[j]=u;

            }
        }
    }
}
int lowestFactor(int n){
    if(n==0){
        return 1;
    }
    if(n<=3){
        return n;
    }
    if((n&1)==0){
        return 2;
    }
    if(primes[(n-3)/2]==0){
        return n;
    }
    return primes[(n-3)/2];
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