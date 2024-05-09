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
int even_ct[N];
int subtree_sum[N];
void dfs(int vertex,int par=0)
{
    if(vertex%2==0) even_ct[vertex]++;
    subtree_sum[vertex]+=vertex;
    for(auto child:g[vertex])
    {
        if(child==par) continue;
        dfs(child,vertex);
        even_ct[vertex]+=even_ct[child];
        subtree_sum[vertex]+=subtree_sum[child];
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
    cout<<"Subtree Sum"<<endl;  
    for(int i=1;i<=n;i++) cout<<subtree_sum[i]<<" ";
    cout<<endl;
    cout<<"Even Count"<<endl;
    for(int i=1;i<=n;i++) cout<<even_ct[i]<<" ";
    // int q;
    // cin>>q;
    // while(q--)
    // {
    //     int v;
    //     cin>>v;

    // }


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

