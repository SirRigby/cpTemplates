#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout); freopen("error.txt","w", stderr) ;
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

struct Mos{
    static const int BLK=300;

    int res=0;
    void add(int l, vector<int> &v){

    }
    void rem(int l,vector<int> &v){

    }
    
    struct Query{
        int l,r,ind;
        bool operator < (const Query & other){
            if(l/BLK!=(other.l)/BLK){
                return l<(other.l);
            }
            if((l/BLK)&1){
                return r<(other.r);
            }
            return r>(other.r);
        }
    };

    vector<Query> queries;

    Mos(int q){
        queries.resize(q);
    }

    vector<int> solve(vector<int> &v){
        vector<int> ans(queries.size());
        sort(queries.begin(),queries.end());
        int pl=0,pr=-1;
        for(auto &q: queries){
            while(pl>q.l){
                pl--;
                add(pl,v);
            }
            while(pl<q.l){
                rem(pl,v);
                pl++;
            }
            while(pr<q.r){
                pr++;
                add(pr,v);
            }
            while(pr>q.r){
                rem(pr,v);
                pr--;
            }
            ans[q.ind]=res;
        }
        return ans;
    }
};

struct MosOnline{
    static const int BLK=300;

    struct Block{
        int res=0;

        void add(int x){

        }
        void merge(Block &blk){

        }
    };

    vector<Block> blocks;

    MosOnline(vector<int> &v){
        int n=v.size();
        blocks.resize((n+BLK)/BLK);
        for(int i=0;i<n;i++){
            blocks[i/BLK].add(v[i]);
        }
    }

    int solve(int l, int r, vector<int> &v){
        Block ans;
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