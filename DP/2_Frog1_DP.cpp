#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long >
#define fr first
#define sc second
#define INF LLONG_MAX
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
int stones[N];
int dp[N];
int func(int i)
{
    if(i==0) return 0;
    if(dp[i]!=-1) return dp[i];
    int cost=INT_MAX;
    cost=min(cost,func(i-1)+abs(stones[i]-stones[i-1]));
    if(i>1)
    {
        cost=min(cost,func(i-2)+abs(stones[i]-stones[i-2]));
    }
    return dp[i]=cost;

}

void solve()
{
    int n;
    cin>>n;
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

