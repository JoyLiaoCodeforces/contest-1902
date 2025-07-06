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
    int n,P,l,t;
    cin>>n>>P>>l>>t;
    int tsks=(n+6)/7;
    int mnd=(tsks+1)/2;
    if(mnd*l+tsks*t>=P){
        cout<<n-(P+l+t*2-1)/(l+t*2)<<"\n";
    }else{
        P-=tsks*t;
        cout<<n-(P+l-1)/(l)<<"\n";
    }
}