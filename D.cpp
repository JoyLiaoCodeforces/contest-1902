#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
using pii=pair<int,int>;

void solve();
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)solve();
}

int n,q;
string s;
pii path[200005];
map<pii,set<int>>mp;

bool find(int x,int y,int l,int r){
    l--;
    if(mp.count(pii(x,y))){
        set<int>&a=mp[pii(x,y)];
        int mn=*(a.begin());
        auto mxit=a.end();mxit--;
        int mx=*(mxit);
        if(mn<=l||mx>=r){return 1;}
    }
    x=path[l].first+path[r].first-x;
    y=path[l].second+path[r].second-y;
    // cerr<<"new:"<<x<<","<<y<<"\n";
    if(mp.count(pii(x,y))){
        set<int>&a=mp[pii(x,y)];
        auto it=a.lower_bound(l);
        if(it==a.end()){cerr<<"b\n";return 0;}
        {return ((*it)<=r);}
    }
    // cerr<<"d\n";
    return 0;
}

void solve(){
    cin>>n>>q>>s;
    mp[pii(0,0)]={0};
    path[0]=pii(0,0);
    for(int i=0,x=0,y=0;i<n;i++){
        x+=(s[i]=='R')-(s[i]=='L');
        y+=(s[i]=='U')-(s[i]=='D');
        if(!mp.count(pii(x,y)))mp[pii(x,y)]={};
        mp[pii(x,y)].insert(i+1);
        path[i+1]=pii(x,y);
    }
    for(int x,y,l,r;q--;){
        cin>>x>>y>>l>>r;
        cout<<(find(x,y,l,r)?"yes\n":"no\n");
    }
    
}