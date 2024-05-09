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

int parent[N];

void dfs(int v,int par=-1)
{
    parent[v]=par;
    for(auto child:g[v])
    { 
        if(child==par) continue;
        dfs(child,v);
    }
}

vector<int>path(int v)
{
    vector<int>ans;
    while(v!=-1)
    {
        ans.pb(v);
        v=parent[v];
    }
    reverse(ans.begin(),ans.end());
    return ans;
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
    int x=6;
    int y=7;
    vi path_x=path(x);
    vi path_y=path(y);
    int minLen=min(path_x.size(),path_y.size());

    int lca=-1;
    for(int i=0;i<minLen;i++)
    {
        if(path_x[i]==path_y[i])
        {
            lca=path_x[i];
        }
        else{
            break;
        }
    }
    cout<<lca<<endl;




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

