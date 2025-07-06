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

struct node{
    int cnt=0;
    node* child[26]={};
    void init(){
        cnt=0;
        for(int i=0;i<26;i++)child[i]=NULL;
    }
}T,Tr;
int sz=1,szr=1;
void insert(string &s,int i,node *Ti){
    (*Ti).cnt++;
    if(i==s.length())return;
    int c=s[i]-'a';
    if((*Ti).child[c]==NULL){
        (*Ti).child[c]=new node;
    }
    insert(s,i+1,((*Ti).child[c]));
}
ll ans=0;
void trav(node *Ti,node *Tir,int dp=0){
    ans+=(ll)(*Ti).cnt*(*Tir).cnt*2*dp;
    for(int c=0;c<26;c++)if((*Ti).child[c]!=NULL&&(*Tir).child[c]!=NULL){
        trav((*Ti).child[c],(*Tir).child[c],dp+1);
        ans-=(ll)(*((*Ti).child[c])).cnt*(*((*Tir).child[c])).cnt*2*dp;
    }
    // ans+=t*2*dp;
    return;
}

void solve(){
    cin>>n;
    int org=0;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;org+=s.length();
        insert(s,0,&T);
        reverse(s.begin(),s.end());
        insert(s,0,&Tr);
    }
    trav(&T,&Tr);
    cout<<(ll)org*n*2-ans<<"\n";
}