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
vector<pair<int,int>>g[N];

void dijkstra(int src) {
    vector<int> dist(N, INF);
    vector<int> vis(N, 0);
    set<pair<int, int>> st;

    dist[src] = 0;
    st.insert({0, src});

    while (!st.empty()) {
        auto node = *st.begin();
        st.erase(st.begin());
        int v = node.second; 
        int d = node.first; 

        for (auto& child : g[v]) {
            int child_v = child.first; // Corrected from child.fr
            int wt = child.second; // Corrected from child.sc
            if (dist[v] + wt < dist[child_v]) {
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }
}

void solve()
{
    
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

