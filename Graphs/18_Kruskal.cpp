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

const int N=400;
int parent[N];
int sze[N];

void make(int v)
{
    parent[v]=v;
    sze[v]=1;
}

int Find(int v)
{
    if(parent[v]==v) return v;
    return parent[v]=Find(parent[v]);
}


void Union(int a,int b)
{
    a=Find(a);
    b=Find(b);
    if(a!=b)
    {
        if(sze[b]>sze[a])
        {
            swap(a,b);
        }
        parent[b]=a;
        sze[a]+=sze[b];
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>>edges;
    while(m--)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.pb({wt,{u,v}});
    }   
    sort(all(edges));

    for(int i=1;i<=n;i++) make(i);
    int total_cost=0;
    for(auto &edge:edges)
    {
        int wt=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;
        if(Find(u)==Find(v)) continue;
        Union(u,v);
        total_cost+=wt;
        cout<<u<<" "<<v<<endl;
    }
    cout<<total_cost<<endl;
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

