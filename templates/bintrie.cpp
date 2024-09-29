#include<bits/stdc++.h>
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

struct Bintrie{
    
    struct Node{
        Node* links[2];
        Node(){
            memset(links,0,sizeof(links));
        }
    };

    Node* root=new Node;
    int cnt=0;
    int len=32;

    void insert(int n){
        Node* r= root;
        cnt++;
        for(int i=len-1;i>=0;i--){
            if((r->links)[(((1<<i)&n)!=0)]==nullptr){
                (r->links)[(((1<<i)&n)!=0)]=new Node;
            }
            r=(r->links)[(((1<<i)&n)!=0)];
        }
    }

    void insert(string &s){
        Node* r= root;
        cnt++;
        for(int i=0;i<s.size();i++){
            if((r->links)[s[i]-'0']==nullptr){
                (r->links)[s[i]-'0']=new Node;
            }
            r=(r->links)[s[i]-'0'];
        }
    }

    bool search(int n){
        Node *r= root;
        for(int i=len-1;i>=0;i--){
            if((r->links)[((1<<i)&n)!=0]==nullptr){
                return 0;
            }
            r=(r->links)[((1<<i)&n)!=0];
        }
        return 1;
    }

    bool search(string &s){
        Node *r= root;
        for(int i=0;i<s.size();i++){
            if((r->links)[s[i]-'0']==nullptr){
                return 0;
            }
            r=(r->links)[s[i]-'0'];
        }
        return 1;
    }

    int searchMax(int n){
        if(cnt<1){
            return -1;
        }
        Node* r=root;
        int p=0;
        for(int i=len-1;i>=0;i--){
            if((r->links)[(((1<<i)&n)==0)]!=nullptr){
                p|=(1<<i);
                r=(r->links)[(((1<<i)&n)==0)];
            }
            else{
                r=(r->links)[(((1<<i)&n)!=0)];
            }
        }
        return p;
    }

    int searchMax(string &s){
        if(cnt<1){
            return -1;
        }
        Node* r=root;
        int p=0;
        for(int i=0;i<s.size();i++){
            if((r->links)[(s[i]-'0')^1]!=nullptr){
                p|=(1<<i);
                r=(r->links)[(s[i]-'0')^1];
            }
            else{
                r=(r->links)[(s[i]-'0')];
            }
        }
        return p;
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