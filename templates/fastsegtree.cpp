#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

typedef long long td;
//
static const td identityz=0;
struct Node{
    td val;
    Node(){
        val=identityz;
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
// static const int NSG=100000;
// Node arr[NSG];
// //s=2^ceil(log2(n))
// //slg=log2(s)
// //treenode size = s/2^(floor(log2(slg)))
// Node treenodes[8192];
struct Segtree{

    vector<Node> treenodes, arr;
    int n;
    int s;

    Segtree(int n1){
        s=1;
        int slg=0;
        n=n1;
        while(s<n){
            s<<=1;
            slg++;
        }
        for(int i=31;i>=0;i--){
            if((1<<i)&slg){
                s>>=i;
                break;
            }
        }
        arr.resize(n);
        treenodes.resize(s);
    }

    Segtree(int n1, vector<Node>& arr1) {
        s=1;
        int slg=0;
        n=n1;
        while(s<n){
            s<<=1;
            slg++;
        }
        for(int i=31;i>=0;i--){
            if((1<<i)&slg){
                s>>=i;
                break;
            }
        }
        arr=arr1;
        treenodes.resize(s);
        build(0,n-1,1,arr);
    }

    void bruteCombine(int left,int right,int index,Node & ans ,vector<Node>&arr){
        if(index<s){
            ans.merge(ans,treenodes[index]);
            return;
        }
        for(int i=left;i<=right;i++){
            ans.merge(ans,arr[i]);
        }
    }
    void build(int start, int end, int index, vector<Node>& arr){
        if(s<=index){
            return;
        }
        int mid=(start+end)/2;
        Node left,right;
        if((index<<1)<s){
            build(start,mid,index<<1,arr);
        }
        bruteCombine(start,mid,index<<1,left,arr);
        if(((index<<1)|1)<s){
            build(mid+1,end,(index<<1)|1,arr);
        }
        bruteCombine(mid+1,end,(index<<1)|1,right,arr);
        treenodes[index].merge(left,right);
    }

    void update(int start, int end, int index, int queIndex, td val){
        if(index>=s){
            arr[queIndex].apply(val);
            return;
        }
        int mid=(start+end)/2;
        Node l,r;
        if (mid>=queIndex){
            update(start,mid,2*index,queIndex,val);
        }
        else{
            update(mid+1,end,2*index+1,queIndex,val);
        }
        bruteCombine(start,mid,(index<<1),l,arr);
        bruteCombine(mid+1,end,(index<<1)|1,r,arr);
		treenodes[index].merge(l,r); 
    }

    Node query(int start, int end, int index, int left, int right){
        if(start>right || end<left){
            return Node();
        }
        if(index>=s){
            Node ans;
            bruteCombine(max(start,left),min(end,right),index,ans,arr);
            return ans;
        }
        if (start>=left && end<=right){
            return treenodes[index];
        }
        int mid=(start+end)>>1;
        Node l=query(start,mid,(index<<1),left,right);
        Node r=query(mid+1,end,(index<<1)|1,left,right);
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

    td findIndexOfPrefixSumLowerBound(td target){
        int start=0,end= n-1;
        int index=1;
        int mid=(start+end)>>1;
        while(start!=end){
            if(index>=s){
                int ans=start;
                while(target>0 && ans<=end){
                    target-=arr[ans].val;
                    if(target<=0){
                        return ans;
                    }
                    ans++;
                }
                return end;
            }
            Node leftval;
            bruteCombine(start,mid,(index<<1),leftval,arr);
            if(leftval.val>=target){
                index=(index<<1);
                end=mid;
            }
            else{
                index=(index<<1)|1;
                target-=leftval.val;
                start=mid+1;
            }
        }
        return start;
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;  
}