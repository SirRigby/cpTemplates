#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

struct Matrix{
    int n,m;
    vector<vector<int>> v;
    int M=1e9+7;

    Matrix(vector<vector<int>> &v1){
        n=v1.size();
        m=n;
        v=v1;
    }
    Matrix(int n1){
        n=n1;
        m=n;
        v.resize(n,vector<int>(n,0));
    }
    Matrix(int n1, char isIdentity){
        n=n1;
        m=n;
        v.resize(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            v[i][i]=1;
        }
    }
    Matrix(int n1,int m1){
        n=n1;
        m=m1;
        v.resize(n,vector<int> (m,0));
    }

    Matrix operator *(Matrix a){
        Matrix ans(n,a.m);
        if(m!=a.n){
            return ans;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<a.m;j++){
                for(int k=0;k<m;k++){
                    ans.v[i][j]=(ans.v[i][j]+(v[i][k]*1LL*a.v[k][j])%M)%M;
                }
            }
        }
        return ans;
    }
};

Matrix matpow(Matrix x, int y, int M){
    Matrix r(x.n,'^');
    Matrix z(x.v);
    while(y){
        if(y&1){
            r=(r*z);
        }
        z=(z*z);
        y>>=1;
    }
    return r;
}

static const int M=1e9+7;

int findRecur(vector<int> &coeff, vector<int> &bases, int n){
    int deg=coeff.size();
    if(n<deg){
        return bases[n];
    }
    Matrix coeMat(deg);
    for(int i=0;i<deg;i++){
        coeMat.v[0][i]=coeff[deg-1-i];
    }
    for(int i=1;i<deg;i++){
        coeMat.v[i][i-1]=1;
    }
    Matrix baseMat(deg,1);
    for(int i=0;i<deg;i++){
        baseMat.v[i][0]=bases[deg-1-i];
    }
    n=(n-deg+1);
    coeMat=matpow(coeMat,n,M);
    coeMat=coeMat*baseMat;
    return coeMat.v[0][0];
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