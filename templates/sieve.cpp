#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

static const int MSV=1e6;
vector<int> primes;
void sieve(vector<int>& primenos, int MS=MSV ){
    bool isprime[MS/2];
    for(int i=0;i<MS/2;i++){
        isprime[i]=true;
    }
    if(MS>=2){
        primenos.push_back(2);
    }
    //num=3+2i
    for(int i=0;(3+2*i)*(3+2*i)<=(MS);i++){
        int u=3+2*i;
        if(isprime[i]){
            for(int j=(u*u-3)/2;j<MS/2;j+=u){
                isprime[j]=0;
            }
        }
    }
    for(int i=0;i<MS/2;i++){
        if(isprime[i]){
            primenos.push_back(3+2*i);
        }
    }
}


int squart(long long h){
    int ans=0;
    for(int i=30;i>=0;i--){
        if((ans*1LL+(1<<i))*(ans*1LL+(1<<i))<=h){
            ans+=(1<<i);
        }
    }
    return ans;
}

vector<long long> segSieve(long long left, long long right){
    vector<long long> v;
    left=max(left,2*1LL);
    if(left<=2 && right>=2){
        v.push_back(2);
    }

    if((left&1)==0){
        left++;
    }
    if((right&1)==0){
        right--;
    }
    if(right<left){
        return v;
    }

    int range=(right-left)/2+1;
    bool isprime[range];
    for(int i=0;i<range;i++){
        isprime[i]=true;
    }
    vector<int> primes;
    sieve(primes,squart(right));
    for(long long i: primes){
        if(i==2){
            continue;
        }
        for(long long j=max(i*i,((((left+i-1)/i)|1)*i));j<=right;j+=2*i){
            isprime[(j-left)/2]=0;
        }
    }
    for(int i=0;i<range;i++){
        if(isprime[i]){
            v.push_back(left+2*i);
        }
    }
    return v;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
        vector<long long> v=segSieve(a,b);
        for(auto i:v){
            cout<<i<<endl;
        }
        cout<<endl;
    }
    return 0;
}