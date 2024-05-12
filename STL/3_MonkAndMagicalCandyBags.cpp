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

const int N=1e5;
void solve()
{
    int n,k;
    cin>>n>>k;
    multiset<ll>bags;
    for(int i=0;i<n;i++)
    {
        ll candy_ct;
        cin>>candy_ct;
        bags.insert(candy_ct);
    }
    ll total_candies=0;
    for(int i=0;i<k;i++)
    {
        auto last_it=--(bags.end());
        ll candy_ct=*last_it;
        total_candies+=candy_ct;
        bags.erase(last_it);
        bags.insert(candy_ct/2);
    }
    cout<<total_candies<<endl;
}
int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    fast_io;
    test
        solve();
    return 0;
}

