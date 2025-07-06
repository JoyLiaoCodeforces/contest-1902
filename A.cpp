#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
using pii=pair<int,int>;

void solve();
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)solve();
}

void solve(){
    int n;
    string s;
    cin>>n>>s;
    bool z=0;
    for(int i=0;i<n;i++)if(s[i]=='0')z=1;
    cout<<(z?"yes\n":"no\n");
}