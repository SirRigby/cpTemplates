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

int main(){
    return 0;
}