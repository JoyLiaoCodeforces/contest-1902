#include<bits/stdc++.h>
using namespace std;
using ll=long long;
// #define int ll
using pii=pair<int,int>;
 
void solve();
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)solve();
}
 
int n;
string s[1000005]; 
 
struct node{
    int cnt;
    node* child[26];
    void init(){
        cnt=0;
        for(int i=0;i<26;i++)child[i]=NULL;
    }
}*T;
void insert(string &s){
    T->cnt++;
    node*cur=T;
    for(int i=0;i<s.length();i++){
        if(cur->child[s[i]-'a']==NULL){
            cur->child[s[i]-'a']=new node;
            cur->child[s[i]-'a']->init();
        }
        cur=cur->child[s[i]-'a'];
        cur->cnt++;
    }
}
ll ans=0;
void cal(string &s){
    node*cur=T;
    for(int i=0;i<s.length();i++){
        cur=cur->child[s[i]-'a'];
        if(cur==NULL)return;
        ans-=cur->cnt*2;
    }
}

void solve(){
    T=new node;
    T->init();
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
        ans+=s[i].length();
        insert(s[i]);
        reverse(s[i].begin(),s[i].end());
    }
    ans*=2*n;
    for(int i=0;i<n;i++)cal(s[i]);
    cout<<ans<<"\n";
}