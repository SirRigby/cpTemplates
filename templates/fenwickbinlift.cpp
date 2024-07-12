#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

struct Fenwick{

    typedef long long td;

    int n;
    vector<td> v;
    td identity=0;

    Fenwick(int n1){
        n=n1;
        v.resize(n,identity);
    }

    void upd(int pos, td val){
        for(;pos<n;pos|=(1+pos)){
            //
            v[pos]+=val;
        }
    }

    td que(int pos){
        td h=identity;
        for(;pos>=0;pos&=(1+pos),pos--){
            //
            h+=v[pos];
        }
        return h;
    }

    td search(td val){
        td h=identity;
        int pos=-1;
        for(int i=30;i>=0;i--){
            td newh=identity;
            int newpos=pos+(1<<i);
            if(newpos<n){
                //
                newh=h+v[newpos];
            }
            if(newpos<n && newh<val){
                h=newh;
                pos=newpos;
            }
        }
        return pos+1;
    }

    Fenwick(int n1, vector<td>& a, int a_size){
        n=n1;
        v.resize(n,identity);
        for(int i=0;i<a_size;i++){
            upd(i,a[i]);
        }
    }

};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        
    }
    return 0;
}