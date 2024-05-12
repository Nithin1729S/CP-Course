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

const int N=2e5+10;
int multiples_ct[N];
int hsh[N];
void solve()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        hsh[x]++; //counting occurence of each number
    }
    for(int i=1;i<N;i++)
    {
        for(int j=i;j<N;j+=i)
        {
            multiples_ct[i]+=hsh[j]; //j is a multiple of i and j occurs hsh[j] tines inn the given array
        }
    }
    for(int i=0;i<10;i++)
    {
        cout<<i<<" "<<multiples_ct[i]<<endl;
    }
    int q;
    cin>>q;
    while(q--)
    {
        int p,q;
        cin>>p>>q;
        ll lcm=(p*1LL*q)/__gcd(p,q);  //lcm calculation
        ll ans=multiples_ct[p]+multiples_ct[q];
        if(lcm<N)
        {
            ans-=multiples_ct[lcm]; //inclusion exclusion
            
        }
        cout<<ans<<endl;
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

