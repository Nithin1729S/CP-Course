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

void solve()
{
    int n;
    cin>>n;
    take(vec,n);
    vector<vector<int>>subsets;
    int subset_ct=(1<<n);
    for(int mask=0;mask<subset_ct;mask++)
    {
        vector<int>subset;
        for(int i=0;i<n;i++)
        {
            if((mask&(1<<i))!=0)
            {
                subset.pb(vec[i]);
            }
        }
        subsets.pb(subset);
    }
    for(auto it:subsets)
    {
        give(it,it.size());
    }
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

