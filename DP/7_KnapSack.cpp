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
#define fast_io ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define test int t;std::cin>>t;while(t--)
#define take(a,n) vi a(n); for(int i=0;i<n;i++) std::cin >> a[i];
#define give(a,n) for(int i=0;i<n;i++) {std::cout << a[i] << ' ';}std::cout << endl;

const int N=2e5+10;
int wt[108],val[108];
ll dp[105][100005];

ll func(int idx,int wt_left)
{
    if(wt_left==0) return 0;
    if(idx<0) return 0;
    if(dp[idx][wt_left]!=-1) return dp[idx][wt_left];
    
    ll ans=func(idx-1,wt_left);
    if(wt_left-wt[idx]>=0)
    {
        ans=max(ans,func(idx-1,wt_left-wt[idx])+val[idx]);
    }
    return dp[idx][wt_left]=ans;
}
void solve()
{
    int n,w;
    cin>>n>>w;
    for(int i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<func(n-1,w);

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

