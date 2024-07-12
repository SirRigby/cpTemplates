#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

struct Trie{

    struct Node{
        static const int length=26;
        Node* links[length];
        bool flag=false;
        Node(){
            memset(links,0,sizeof(links));
        }
    };

    Node* root= new Node;

    void insert(string &s){
        Node* r= root;
        for(int i=0;i<s.size();i++){
            if((r->links)[s[i]-'a']==nullptr){
                (r->links)[s[i]-'a']=new Node();
            }
            r=r->links[s[i]-'a'];
        }
        r->flag=1;
    }

    bool search(string& s){
        Node* r=root;
        for(int i=0;i<s.size();i++){
            if((r->links)[s[i]-'a']==nullptr){
                return 0;
            }
            r=r->links[s[i]-'a'];
        }
        return r->flag;
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