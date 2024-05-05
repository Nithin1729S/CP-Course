#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long >
#define fr first
#define sc second
#define INF INT_MAX
#define MOD 1000000007
#define pii pair<int,int>
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define clr(x) memset(x,0,sizeof(x))
#define sortUni(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define test int t;cin>>t;while(t--)
#define take(a,n) vi a(n); for(int i=0;i<n;i++) cin >> a[i];
#define give(a,n) for(int i=0;i<n;i++) {cout << a[i] << ' ';}cout << endl;

const int N=1e5+10;
int k;
int stones[N];
int dp[N];

int func(int i)
{
    if(i==0) return 0;
    if(dp[i]!=-1) return dp[i];
    int cost=INF;

    for(int j=1;j<=k;j++)
    {
        if((i-j)>=0) cost=min(cost,func(i-j)+abs(stones[i]-stones[i-j]));
    }
    return dp[i]=cost;

}
void solve()
{
    int n;
    std::cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        cin>>stones[i];
    }
    cout<<func(n-1)<<endl;
}
int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    fast_io;
    // test
        solve();
    return 0;
}

