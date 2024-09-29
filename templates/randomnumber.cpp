#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout); freopen("error.txt","w", stderr) ;
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


int main(){
    //32 bit
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    for(int i=0;i<10;i++){
        cout<<rng()<<endl;
    }

    //64 bit
    mt19937_64 rng2(chrono::steady_clock::now().time_since_epoch().count());
    for(int i=0;i<10;i++){
        cout<<rng2()<<endl;
    }

    return 0;
}