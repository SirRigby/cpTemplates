#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

struct HashGen{

    long long p1=999999751,p2=1000000033;
    long long c=69;
    long long p=71;
    vector<long long> primes={p1,p2};
    int y=primes.size();
    vector<vector<long long>> pref;
    vector<vector<long long>> bip;

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
    HashGen(string &s){
        int sz=s.size();
        pref.resize(y,vector<long long> (sz+1,0));
        bip.resize(y,vector<long long> (sz+1));
        for(int pr=0;pr<y;pr++){
            long long prim=primes[pr];
            long long h=1;
            for(int i=0;i<sz;i++){
                pref[pr][i+1]=(((s[i]-'a'+1+c)*h)%prim+pref[pr][i])%prim;
                h=(h*p)%prim;
            }
            bip[pr][sz]=binpow(h,prim-2,prim);
            for(int i=sz-1;i>=0;i--){
                bip[pr][i]=(bip[pr][i+1]*p)%prim;
            }
        }
    }
    
    vector<long long> que(int i, int j){
        vector<long long> v;
        for(int k=0;k<y;k++){
            long long r=((pref[k][j+1]-pref[k][i])%primes[k]+primes[k])%primes[k];
            r=(r*bip[k][i])%primes[k];
            v.push_back(r);
        }
        return v;
    }

};

struct HashN{
    long long p1=999999751,p2=1000000033;
    long long c=69;
    long long p=71;
    vector<long long> primes={p1,p2};
    int y=primes.size();

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
    //v[i][prime]
    vector<vector<long long>> que(string &s, int n){
        vector<vector<long long>> v;
        if(s.size()<n){
            return v;
        }
        int sz=s.size();
        v.resize(s.size()-n+1,vector<long long> (y));
        for(int pr=0;pr<y;pr++){
            long long r=0;
            long long minv=binpow(p,n,primes[pr]);
            for(int i=0;i<sz;i++){
                r=(r*p)%primes[pr];
                if(i>=n){
                    r=(r-((s[i-n]-'a'+1+c)*minv)%primes[pr])%primes[pr];
                    r=(r+primes[pr])%primes[pr];
                }
                r=(r+(s[i]-'a'+1+c))%primes[pr];
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