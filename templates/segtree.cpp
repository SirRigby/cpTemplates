#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

struct Segtree{
    typedef long long td;
    //
    static const td identity=0;

    struct Node{
        td val;
        Node(){
            val=identity;
        }
        Node(long long p){
            val=p;
        }
        //
        void merge(Node &n1, Node &n2){
            val=n1.val+n2.val;
        }
        //
        void apply(td a){
            val=a;
        }
    };

    vector<Node> tree;
    int n;
    int s;

    Segtree(int n1){
        int s=1;
        n=n1;
        while(s<2*n){
            s<<=1;
        }
        tree.resize(s,Node());
    }

    Segtree(int n1, td arr[]){
        int s=1;
        n=n1;
        while(s<2*n){
            s<<=1;
        }
        tree.resize(s,Node());
        build(0,n-1,1,arr); 
    }

    void build(int start, int end, int index, td arr[]){
        if(start==end){
            tree[index]=Node(arr[start]);
            return;
        }
        int mid=(start+end)/2;
        build(start,mid,index<<1,arr);
        build(mid+1,end,(index<<1)|1,arr);
        tree[index].merge(tree[(index<<1)|1],tree[index<<1]);
    }

    void update(int start, int end, int index, int queIndex, td val){
        if(start==end){
            tree[index].apply(val);
            return;
        }
        int mid=(start+end)/2;
        if (mid>=queIndex){
            update(start,mid,2*index,queIndex,val);
        }
        else{
            update(mid+1,end,2*index+1,queIndex,val);
        }
        tree[index].merge(tree[2*index],tree[2*index+1]);
    }

    Node query(int start, int end, int index, int left, int right){
        if(start>right || end<left){
            return Node();
        }
        if (start>=left && end<=right){
            return tree[index];
        }
        int mid=(start+end)/2;
        Node l=query(start,mid,2*index,left,right);
        Node r=query(mid+1,end,2*index+1,left,right);
        Node ans;
        ans.merge(l,r);
        return ans;
    }

    void upd(int index, td val){
        update(0,n-1,1,index,val);
    }

    td que(int left, int right){
        Node ans= query(0,n-1,1,left,right);
        return ans.val;
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