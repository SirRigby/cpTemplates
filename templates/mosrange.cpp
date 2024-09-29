#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout); freopen("error.txt","w", stderr) ;
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

struct MosOnline{
    static const int BLK=300;
    static const long long id=0;

    struct Block{
        long long res=id;
        void add(long long x){
            
        }
        void addrange(long long x){
            
        }
        void merge(Block &blk){
            
        }
    };
    struct Lazy{
        long long out=id;
        void add(long long x){
            
        }
    };
    void updateEle(int i, vector<long long>&v, long long res){

    }

    vector<Block> blocks;
    vector<Lazy> lazy;

    void updateBlock(int i, vector<long long> &v){
        blocks[i]= Block();
        for(int j=0;j<BLK;j++){
            if(j+i*BLK==v.size()){
                break;
            }
            blocks[i].add(v[j+i*BLK]);
        }
    }

    void apply(int l, vector<long long>&v){
        if(lazy[l].out==id){
            return;
        }
        for(int i=l*BLK;i<min((int)v.size(),(l+1)*(BLK));i++){
            updateEle(i,v,lazy[l].out);
        }
        lazy[l].out=id;
    }

    MosOnline(vector<long long> &v){
        int n=v.size();
        blocks.resize((n+BLK)/BLK);
        lazy.resize((n+BLK)/BLK);
        for(int i=0;i<n;i++){
            blocks[i/BLK].add(v[i]);
        }
    }

    void upd(int l, int r, vector<long long> &v, long long x){
        if(l%BLK){
            apply(l/BLK,v);
        }
        if((r+1)%BLK){
            apply(r/BLK,v);
        }
        int u=-1;
        while(l<=min(r,(int)v.size()-1) && l%BLK){
            if(u==-1){
                u=l/BLK;
            }
            updateEle(l,v,x);
            l++;
        }
        if(u!=-1){
            updateBlock(u,v);
        }
        u=-1;
        while(l<=r && (r+1)%BLK){
            if(u==-1){
                u=r/BLK;
            }
            updateEle(r,v,x);
            r--;
        }
        if(u!=-1){
            updateBlock(u,v);
        }
        if(l<=r){
            for(int i=l/BLK;i<=r/BLK;i++){
                blocks[i].addrange(x);
                lazy[i].add(x);
            }
        }
    }

    long long que(int l, int r, vector<long long> &v){
        Block ans;
        if(l%BLK){
            apply(l/BLK,v);
        }
        if((r+1)%BLK){
            apply(r/BLK,v);
        }
        while(l%BLK && l<=min(r,(int)v.size()-1)){
            ans.add(v[l++]);
        }
        while(l<=r && (r+1)%BLK){
            ans.add(v[r--]);
        }
        if(l<=r){
            for(int i=l/BLK;i<=r/BLK;i++){
                ans.merge(blocks[i]);
            }
        }
        return ans.res;
    }

};

int main(){
    return 0;
}