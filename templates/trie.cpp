#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

struct Trie{

    char offset='a';
    static const int length=26;

    struct Node{
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
            if((r->links)[s[i]-offset]==nullptr){
                (r->links)[s[i]-offset]=new Node();
            }
            r=r->links[s[i]-offset];
        }
        r->flag=1;
    }

    bool search(string& s){
        Node* r=root;
        for(int i=0;i<s.size();i++){
            if((r->links)[s[i]-offset]==nullptr){
                return 0;
            }
            r=r->links[s[i]-offset];
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