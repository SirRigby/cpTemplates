#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


/*
    [caplist](params)->type{
        body
    }

    [  ]: no scope
    [x ]: x by value
    [&x]: x by ref
    [= ]: local scope by value
    [& ]: local scope by ref
*/


int main(){
    int n=6;
    int a[]={5,4,2,1,4,7};

    sort(a,a+n,[](int &a, int &b){return a%5<b%5;});

    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;

    auto cmp= [](const int &a, const int &b){return a%3<b%3;};
    set<int,decltype(cmp)> s(cmp);
    for(int i=0;i<n;i++){
        s.insert(a[i]);
    }
    // for(auto i:s){
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    return 0;
}