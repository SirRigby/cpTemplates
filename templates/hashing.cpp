#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

struct HashGen{

    static const int p1=999999751,p2=1000000033;
    int c=69;
    int p=71;
    const vector<int> primes={p1,p2};
    int y=primes.size();
    vector<vector<int>> pref;
    vector<vector<int>> bip;

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
    HashGen(string &s){
        int sz=s.size();
        pref.resize(y,vector<int> (sz+1,0));
        bip.resize(y,vector<int> (sz+1));
        for(int pr=0;pr<y;pr++){
            int prim=primes[pr];
            int h=1;
            for(int i=0;i<sz;i++){
                pref[pr][i+1]=((1LL*(s[i]-'a'+1+c)*h)%prim+pref[pr][i]);
                if(pref[pr][i+1]>=prim){
                    pref[pr][i+1]-=prim;
                }
                h=(1LL*h*p)%prim;
            }
            bip[pr][sz]=binpow(h,prim-2,prim);
            for(int i=sz-1;i>=0;i--){
                bip[pr][i]=(1LL*bip[pr][i+1]*p)%prim;
            }
        }
    }
    
    vector<int> que(int i, int j){
        vector<int> v;
        for(int k=0;k<y;k++){
            int r=(pref[k][j+1]-pref[k][i]);
            if(r<0){
                r+=primes[k];
            }
            if(r>=primes[k]){
                r-=primes[k];
            }
            r=(1LL*r*bip[k][i])%primes[k];
            v.push_back(r);
        }
        return v;
    }

};

struct HashN{
    int p1=999999751,p2=1000000033;
    int c=69;
    int p=71;
    vector<int> primes={p1,p2};
    int y=primes.size();

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
    //v[i][prime]
    vector<vector<int>> que(string &s, int n){
        vector<vector<int>> v;
        if(s.size()<n){
            return v;
        }
        int sz=s.size();
        v.resize(s.size()-n+1,vector<int> (y));
        for(int pr=0;pr<y;pr++){
            int r=0;
            int minv=binpow(p,n,primes[pr]);
            for(int i=0;i<sz;i++){
                r=(1LL*r*p)%primes[pr];
                if(i>=n){
                    r-=(1LL*(s[i-n]-'a'+1+c)*minv)%primes[pr];
                    if(r<0){
                        r+=primes[pr];
                    }
                    if(r>=primes[pr]){
                        r-=primes[pr];
                    }
                }
                r+=(s[i]-'a'+1+c);
                if(r>=primes[pr]){
                    r-=primes[pr];
                }
                if(i>=n-1){
                    v[i-n+1][pr]=r;
                }
            }
        }
        return v;
    }

};


int main(){
    
    return 0;
}