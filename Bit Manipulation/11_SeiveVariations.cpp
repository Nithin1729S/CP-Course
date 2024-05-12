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
vector<int>lp(N);
vector<int>hp(N);

void solve()
{
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2;i<N;i++)
    {
        if(isPrime[i])
        {
            lp[i]=hp[i]=i;
            for(int j=2*i;j<N;j+=i)
            {
                isPrime[j]=false;
                hp[j]=i;
                if(lp[j]==0) lp[j]=i;
            }
        }
    }

    for(int i=1;i<100;i++)
    {
        cout<<lp[i]<<" "<<hp[i]<<endl;
    }
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

