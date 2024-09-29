#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int binpow(int x, int y, int M){
    int r=1;
    int z=x;
    if(z>=M){
        z-=M;
    }
    while(y){
        if(y&1){
            r=(1LL*r*z)%M;
        }
        z=(1LL*z*z)%M;
        y>>=1;
    }
    return r;
}

// 1+x+x^2+...+x^y
int binsum(int x, int y, int M){
    long long z=1;
    long long sum=1;
    long long r=x;
    while(y){
        if(y&1){
            sum=(z+(sum*r)%M)%M;
        }
        z+=(r*z)%M;
        z%=M;
        r*=r;
        r%=M;
        y>>=1;
    }
    return sum;
}


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