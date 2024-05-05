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

const int N=1e5+10;
vi a(N);
int dp[N];

int lis(int i)
{
    if(dp[i]!=-1) return dp[i];
    int ans=1;
    for(int j=0;j<i;j++)
    {
        if(a[i]<a[j])
        {
            ans=max(ans,lis(j)+1);
        }
    }
    return dp[i]=ans;
}


void solve()
{
    int n;
    cin>>n;
    memset(dp,-1,size(dp));
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int res=0;
    for(int i=0;i<n;i++)
    {
        res=max(res,lis(i));
    }
    cout<<res<<endl;

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

