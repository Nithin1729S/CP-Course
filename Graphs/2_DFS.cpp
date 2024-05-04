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
vector<int>graph[N];
bool vis[N];

void dfs(int vertex)
{   
    vis[vertex]=true;
    cout<<vertex<<" ";
    for(int child:graph[vertex])
    {
        if(!vis[child]) dfs(child);
    }
} 

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].pb(v2);
        graph[v2].pb(v1);
    }
    dfs(1);

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

