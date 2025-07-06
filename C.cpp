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

int n,a[200005];

int gcd(int a,int b){
    return (a>0?gcd(b%a,a):b);
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    if(n==1){
        cout<<1<<"\n";
        return;
    }
    sort(a,a+n);
    int g=a[n-1]-a[0];
    for(int i=1;i<n;i++)if(a[i-1]!=a[i])g=gcd(g,a[i]-a[i-1]);
    int fnd=a[n-1]-g;
    for(int i=n-1;i>=0;i--){
        if(a[i]==fnd)fnd-=g;
        else if(a[i]<fnd)break;
    }
    int ans=0;
    for(int i=0;i<n;i++)ans+=(a[n-1]-a[i])/g;
    cout<<min(ans+(a[n-1]-fnd)/g,ans+n+1)<<"\n";
}