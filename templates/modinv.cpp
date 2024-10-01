#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout); freopen("error.txt","w", stderr) ;
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

int extendedEuclid(int a, int b, int &x, int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int q=a/b;
    int x1,y1;
    int d=extendedEuclid(b,a-q*b,x1,y1);
    x=y1;
    y=x1-y1*q;
    return d;
}

int modinv(int a, const int M){
    bool isprime=1;
    if(isprime){
        return binpow(a,M-2,M);
    }
    int x,y;
    extendedEuclid(a,M,x,y);
    return x;
}

int main(){
    return 0;
}