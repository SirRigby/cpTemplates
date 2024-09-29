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
};
struct Update {
    td val;
    Update(){ 
        val = identityz;
    }
    Update(td val1) { 
        val = val1;
    }
    void apply(Node &a, int start, int end) { 
        a.val += val*(end - start + 1); 
    }
    void combine(Update& new_update, int start, int end){
        val += new_update.val;
    }
};
// static const int NSG=100000;
// Node arr[NSG];
// //s=2^ceil(log2(n))
// //slg=log2(s)
// //treenode size = s/2^(floor(log2(slg)))
// Node treenodes[8192];
// Update lazy[8192];
struct Segtree{
 
    int n;
    int s;
    vector<Node> arr, treenodes;
    vector<Update> lazy;
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
        lazy.resize(s);
        //build(0,n-1,1,arr);
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
        lazy.resize(s);
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
 
    void prop(int index, int start, int end){
        if( index<s && lazy[index].val!=identityz ){
            int mid=(start+end)>>1;
            propdown((index<<1),start,mid,lazy[index]);
            propdown((index<<1)|1,mid+1,end,lazy[index]);
            lazy[index]=Update();
        }
    }
 
    void propdown(int index, int start, int end, Update& parent){
        if(index<s){
            lazy[index].combine(parent,start,end);
            parent.apply(treenodes[index],start,end);
        }
        else{
            for(int i=start;i<=end;i++){
                parent.apply(arr[i],i,i);
            }
        }
    }
    
    void update(int start, int end, int index, int left,int right, Update& parent){
        if(start>right || end<left){
            return;
        }
        if(start>=left && end<=right){
            propdown(index, start, end, parent);
            return;
        }   
        if(s<=index){
            propdown(index,max(left,start),min(right,end),parent);
            return;
        }
        prop(index,start,end);
        int mid=(start+end)>>1;
	    update(start,mid,(index<<1),left,right,parent);
		update(mid+1,end,(index<<1)|1,left,right,parent);
 
        Node l,r;
        bruteCombine(start,mid,(index<<1),l,arr);
        bruteCombine(mid+1,end,(index<<1)|1,r,arr);
		treenodes[index].merge(l,r);
    }
 
    Node query(int start, int end, int index, int left, int right){
        if(start>right || end<left){
            return Node();
        }
        prop(index,start,end);
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
 
    void upd(int left,int right, td val){
        Update newUpdate= Update(val);
        update(0,n-1,1,left,right,newUpdate);
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
            prop(index,start,end);
            if(index>=s){
                prop(index*2,start,mid);
                prop(index*2+1,mid+1,end);
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
            bruteCombine(start,mid,index<<1,leftval,arr);
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
    
    /*
        n=2^18
        nodes needed= 2^18/2^(floor(log2(19)))  + 2^18

        n=2^15
        2^15/16
    */
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    return 0;
}