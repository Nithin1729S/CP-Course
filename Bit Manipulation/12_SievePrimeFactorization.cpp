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

const int N=1e7+10;
vector<bool>isPrime(N,1);
vector<int>lp(N,0);
vector<int>hp(N,0);
void solve()
{
    isPrime[0]=1;
    isPrime[1]=1;
    for(int i=2;i<N;i++)
    {
        if(isPrime[i])
        {
            lp[i]=hp[i]=i;
            for(int j=2*i;j<N;j+=i)
            {
                isPrime[j]=false;
                hp[j]=i;
                if(lp[j]) lp[j]=i;
            }
        }
    }

    int num=33;
    vi prime_factors;
    while(num>1)
    {
        int prime_factor=hp[num];
        while(num%prime_factor==0)
        {
            num/=prime_factor;
            prime_factors.pb(prime_factor);
        }
    }
    give(prime_factors,prime_factors.size());
}
int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    fast_io;
    //test
        solve();
    return 0;
}

