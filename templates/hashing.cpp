#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout); freopen("error.txt","w", stderr) ;
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


// rolling/permutation
struct HashGen{

    static const int p1=999999751,p2=1000000033;
    int c=69;
    int p=1e9+7;
    const vector<int> primes={p1,p2};
    int y=primes.size();
    vector<vector<int>> pref;
    vector<vector<int>> bip;

    int binpow(long long x, int y, long long M){
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
    HashGen(vector<int> &s){
        int sz=s.size();
        pref.resize(y,vector<int> (sz+1,0));
        bip.resize(y,vector<int> (sz+1));
        for(int pr=0;pr<y;pr++){
            int prim=primes[pr];
            int h=1;
            for(int i=0;i<sz;i++){
                pref[pr][i+1]=((1LL*(s[i]+c)*h)%prim+pref[pr][i]);
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

// set
struct SetHash{
    static const int M=1e9+7;
    vector<int> seta;
    int randomno;
    int pw=78;

    int binpow(int x, int y, const int M){
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

    SetHash(vector<int> &v){
        seta.resize(v.size()+1);
        seta[0]=0;
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        randomno=rng();
        while(randomno>=M){
            randomno-=M;
        }
        for(int i=0;i<v.size();i++){
            int ele=randomno+v[i];
            seta[i+1]=binpow(ele,pw,M);
            seta[i+1]+=seta[i];
            if(seta[i+1]>=M){
                seta[i+1]-=M;
            }
        }
    }

    int que(int i, int j){
        int res=seta[j+1]-seta[i];
        if(res<0){
            res+=M;
        }
        return res;
    }
};

// xor
struct XorHash{
    map<unsigned long long, unsigned long long> mping;
    set<unsigned long long> used={0};
    vector<unsigned long long> xora;

    XorHash(vector<int>& v){
        xora.resize(v.size()+1);
        xora[0]=0;
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        for(int i=0;i<v.size();i++){
            unsigned long long randomno;
            if(mping.find(v[i])==mping.end()){
                randomno=rng();
                while(used.find(randomno)!=used.end()){
                    randomno=rng();
                }
                mping[v[i]]=randomno;
                used.insert(randomno);
            }
            else{
                randomno=mping[v[i]];
            }
            xora[i+1]=xora[i]^randomno;
        }
    }

    unsigned long long que(int i, int j){
        unsigned long long res=xora[j+1]^xora[i];
        return res;
    }

};

int main(){

    return 0;
}