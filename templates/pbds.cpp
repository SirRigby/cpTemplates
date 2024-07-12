#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
  //////////////
 //less_equal//
//////////////


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    oset pbds;

    pbds.insert(5);

    pbds.order_of_key(5);
    *(pbds.find_by_order(0));

    return 0;
}