#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define fr first
#define sc second
#define INF LLONG_MAX
#define MOD 1000000007
#define pii pair<int,int>
#define int long long
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define clr(x) memset(x,0,sizeof(x))
#define sortUni(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define f0(i,n)  for(int i=0;i<(int)n;i++)
#define f1(i,n)  for(int i=1;i<=(int)n;i++)
#define test int t;cin>>t;while(t--)
#define take(a,n) vi a(n); f0(i,n) cin >> a[i];
#define give(a,n) f0(i,n){cout << a[i] << ' ';}cout << endl;

const int N=1e6+10;
int n;
long long m;
long long trees[N];

bool isWoodSuf(int h)
{
    long long wood=0;
    for(int i=0;i<n;i++)
    {
        if(trees[i]>=h)
        {
            wood += (trees[i]-h);
        }
    }
    return wood>=m;
}

void solve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>trees[i];

    }
    long long lo=0;
    long long hi=1e9;
    long long mid;
    while(hi-lo>1)
    {
        mid=(hi+lo)/2;
        if(isWoodSuf(mid))
        {
            lo=mid;
        }
        else
        {
            hi=mid-1;
        }
    }
    if(isWoodSuf(hi)) cout<<hi<<endl;
    else cout<<lo<<endl;

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

