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

const int N=2e3+10;
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
    int n;
    cin>>n;
    vector<pair<int,int>>cities(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>cities[i].first>>cities[i].second;
    }
    vi c(n+1),k(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
    }

    vector<pair<ll,pair<int,int>>>edges;

    //zero node addition
    for(int i=1;i<=n;i++)
    {
        edges.pb({c[i],{0,i}});
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int dist=abs(cities[i].fr-cities[j].fr)+abs(cities[i].sc-cities[j].sc);
            ll cost=dist*1ll*(k[i]+k[j]);
            edges.pb({cost,{i,j}});
        }
    }
     
    sort(all(edges));

    for(int i=1;i<=n;i++) make(i);

    ll total_cost=0;
    vector<int>pwrStations;
    vector<pair<int,int>>connections;

    for(auto &edge:edges)
    {
        int wt=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;
        if(Find(u)==Find(v)) continue;
        Union(u,v);
        total_cost+=wt;
        if(u==0 || v==0) pwrStations.pb(max(u,v));
        else connections.pb({u,v});
        // cout<<u<<" "<<v<<endl;
    }
    cout<<total_cost<<endl;
    cout<<pwrStations.size()<<endl;
    for(int station:pwrStations)
    {
        cout<<station<<" ";
    }
    cout<<endl;
    cout<<connections.size()<<endl;
    for(auto &connection:connections)
    {
        cout<<connection.first<<" "<<connection.sc<<endl;
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

