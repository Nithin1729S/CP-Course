#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long >
#define fr first
#define sc second
#define INF 1e9
#define MOD 1000000007
#define pii pair<int,int>
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define clr(x) memset(x,0,sizeof(x))
#define sortUni(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define fast_io ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define test int t;std::cin>>t;while(t--)
#define take(a,n) vi a(n); for(int i=0;i<n;i++) std::cin >> a[i];
#define give(a,n) for(int i=0;i<n;i++) {std::cout << a[i] << ' ';}std::cout << endl;

const int M=1e9+7;
const int N=1e5+10;
int fact[N];
int binExp(int a,int b,int m)
{
    int ans=1;
    while(b)
    {
        if(b&1) ans=(ans*1ll*a)%m;
        a=(a*1ll*a)%m;
        b>>=1;
    }
    return ans;
}
void solve()
{
    int n,k;
    cin>>n>>k;
    int ans=fact[n];
    ans=(ans*1ll*fact[k])%M;
    int deno=(fact[k-n]*1ll*fact[n])%M;
    ans=(ans*1ll*binExp(deno,M-2,M))%M;
    cout<<ans<<endl;

}
int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    fast_io;
    fact[0]=1;
    for(int i=1;i<N;i++)
    {
        fact[i]=(fact[i-1]*1ll*i)%M;
    }

    test
        solve();
    return 0;
}

