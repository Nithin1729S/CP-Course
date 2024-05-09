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
vector<int>g[N];

int depth[N];
void dfs(int v,int par=-1)
{
    for(auto child:g[v])
    {
        if(child==par) continue;
        depth[child]=depth[v]+1;
        dfs(child,v);
    }
}

void solve()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    int max_depth_node=-1;
    int max_depth=-1;
    for(int i=1;i<=n;i++)
    {
        if(depth[i]>max_depth)
        {
            max_depth=depth[i];
            max_depth_node=i;
        }
        depth[i]=0;
    }
    dfs(max_depth_node);
    for(int i=1;i<=n;i++)
    {
        if(depth[i]>max_depth)
        {
            max_depth=depth[i];
            max_depth_node=i;
        }
        depth[i]=0;
    }
    cout<<max_depth<<endl;

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

