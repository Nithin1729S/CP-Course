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

int binExpRec(int a,int b)
{
    if(b==0) return 1;
    int res=binExpRec(a,b/2);
    if(b&1)
    {
        return (a*(res*1ll*res)%MOD)%MOD;
    }
    else
    {
        return (res*1ll*res)%MOD;
    }
}

int binExpIter(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*1ll*a)%MOD;
        }
        a=(a*1ll*a)%MOD;
        b>>=1;
    }
    return ans;
}
void solve()
{
    cout<<binExpRec(2,3000)<<endl;   
    cout<<binExpIter(2,3000)<<endl;   
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

