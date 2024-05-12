#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define fr first
#define sc second
#define INF 1e9
#define MOD 1000000007
#define pii pair<int, int>
#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortUni(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define fast_io              \
    ios::sync_with_stdio(0); \
    std::cin.tie(0);         \
    std::cout.tie(0)
#define test       \
    int t;         \
    std::cin >> t; \
    while (t--)
#define take(a, n)              \
    vi a(n);                    \
    for (int i = 0; i < n; i++) \
        std::cin >> a[i];
#define give(a, n)                \
    for (int i = 0; i < n; i++)   \
    {                             \
        std::cout << a[i] << ' '; \
    }                             \
    std::cout << endl;

const int N = 500;
ll dist[N][N];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> dist[i][j];
        }
    }
    vi deletion_order(n);
    for (int i = 0; i < n; i++)
    {
        cin >> deletion_order[i];
    }
    reverse(deletion_order.begin(), deletion_order.end());
    vector<ll> ans;
    for (int k = 0; k < n; k++)
    {
        int k_v = deletion_order[k];

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                ll new_dist = dist[i][k_v] + dist[k_v][j];
                dist[i][j] = min(dist[i][j], new_dist);
            }
        }
        ll sum = 0;
        for (int i = 0; i <= k; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                sum += dist[deletion_order[i]][deletion_order[j]];
            }
        }
        ans.pb(sum);
    }
    reverse(all(ans));
    for (auto it : ans)
        cout << it << " ";
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    fast_io;
    // test
    solve();
    return 0;
}
