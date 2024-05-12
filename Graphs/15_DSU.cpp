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

const int N=1e5+10;
int parent[N];
int sze[N];

void make(int v)
{
    parent[v]=v;
    sze[v]=1;
}

int Find(int v)
{
    if(v==parent[v]) return v;
    return parent[v]= Find(parent[v]);
}

void Union(int a,int b)
{
    a=Find(a);  //left
    b=Find(b);  //right
    if(a==b) return;
    else
    {
        //Union by size
        if(sze[a]<sze[b])
        {
            swap(a,b);//make left always bigger
        }
        parent[b]=a;
        sze[a]+=sze[b];
    }
}

void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        make(i);
    }
    while(k--)
    {
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    int connectedComponents=0;
    for(int i=1;i<=n;i++)
    {
        if(Find(i)==i) connectedComponents++;
    }
    cout<<connectedComponents<<endl;

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

