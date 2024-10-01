#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout); freopen("error.txt","w", stderr) ;
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

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

// ax+by=c
bool solve(int a, int b, int c, int &x, int & y, int &g){
    int g=extendedEuclid(a,b,x,y);
    if(c%g){
        return 0;
    }
    int n=c/g;
    x*=n;
    y*=n;
    if(a<0){
        x=-x;
    }
    if(b<0){
        y=-y;
    }
    return 1;
}

int main(){
    return 0;
}