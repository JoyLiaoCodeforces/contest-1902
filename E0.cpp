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
    int cnt;
    int child[26];
    void init(){
        cnt=0;
        for(int i=0;i<26;i++)child[i]=-1;
    }
}T[1000001],Tr[1000001];
int sz=1,szr=1;
void insert(string &s,int &i,int &ti,node*T,int &sz){
    T[ti].cnt++;
    if(i==s.length())return;
    int c=s[i]-'a';
    if(T[ti].child[c]<0){
        T[ti].child[c]=sz;
        T[sz].init();
        sz++;
    }
    i++;
    insert(s,i,T[ti].child[c],T,sz);
}
ll ans=0;
void trav(int &i,int &ir){
    if(i!=0)ans-=(ll)T[i].cnt*Tr[ir].cnt*2;
    for(int c=0;c<26;c++)if(T[i].child[c]>=0&&Tr[ir].child[c]>=0){
        trav(T[i].child[c],Tr[ir].child[c]);
    }
    return;
}
 
void solve(){
    cin>>n;
    // ll org=0;
    int i0=0,i1=0;
    string s;
    T[0].init();Tr[0].init();
    for(int i=0,i0;i<n;i++){
        cin>>s;ans+=s.length();
        i0=i1=0;
        insert(s,i0,i1,T,sz);
        reverse(s.begin(),s.end());
        i0=i1=0;
        insert(s,i0,i1,Tr,szr);
    }
    ans*=n*2;
    i0=i1=0;
    trav(i0,i1);
    // cout<<org*n*2<<"\n";
    cout<<ans<<"\n";
}