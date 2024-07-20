#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


// ->       SORTING

//ascending 
struct compasc{
    bool operator()(int a, int b){
        return a<b;
    }
};

//descending
struct compdesc{
    bool operator()(int a, int b){
        return a>b;
    }
};

//descending pair
struct compdescpair{
    bool operator()(pair<int,int> &a, pair<int,int> &b){
        if(a.first!=b.first){
            return a.first>b.first;
        }
        return a.second>b.second;
    }
};

//ascending pair according to second
struct compinvpair{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b){
        if(a.second!=b.second){
            return a.second<b.second;
        }
        return a.first<b.first;
    }
};

// use const when passing by reference

  //////////////////////////////////
 // comp(a,a) should always be 0 //
//////////////////////////////////



// ->       UPPER AND LOWER BOUNDS

/* 
    lower => first equal or greater
    # First false of comp(*it, val)

    upper => first greater
    # First true of comp(val, *it)

    $$$ comp(a,a) = 0 -> equal(a,b) <=> !comp(a,b) && !comp(b,a)

    Example: comp => a<b

    let v =        1 , 2 , 3 , 4 , 5 , 6 
    comp(*it,4)    T , T , T , F , F , F    [lower]
    comp(4,*it)    F , F , F , F , T , T    [upper]
*/ 


// ->       COMPARATORS FOR SETS AND MAPS

/*

    map<T1,T2,comp> mp

    Do not use less_equal, instead make pair

*/


#define osetp tree<pair<int,int>, null_type,compinvpair, rb_tree_tag,tree_order_statistics_node_update>

int main(){
    int n;
    cin>>n;
    pair<int,int> a[n];
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a,a+n,compdescpair());
    // for(int i=0;i<n;i++){
    //     cout<<a[i].first<<" "<<a[i].second<<endl;
    // }

    set<pair<int,int>,compinvpair> s;
    for(int i=0;i<n;i++){
        s.insert(a[i]);
    }
    for(auto i:s){
        cout<<i.first<<" "<<i.second<<endl;
    }

    osetp pbds;
    for(int i=0;i<n;i++){
        pbds.insert(a[i]);
    }

    // for(auto it:pbds){
    // cout<<it.first<<" "<<it.second<<endl;
    // }

    return 0;
}