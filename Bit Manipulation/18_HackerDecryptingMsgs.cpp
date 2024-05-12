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
const int N=2e6+10;
int a[N];
int hp[N];
int canRemove[N];  //01 array
int hsh[N]; 

vector<int>distinctPF(int x)
{
    vi ans;
    while(x>1)
    {
        int pf=hp[x];
        while(x%pf==0) 
        {
            x/=pf;
        }
        ans.pb(pf);
    }
    return ans;
}
void solve()
{

    for(int i=2;i<N;i++)
    {
        if(hp[i]==0)
        {
            for(int j=i;j<N;j+=i)
            {
                hp[j]=i;
            }
        }
    }

    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        hsh[x]++;
        // cin>>a[i];
    }

    for(int i=2;i<N;i++)
    {
        if(hsh[i])
        {
            for(ll j=i;j<N;j*=i)
            {
                canRemove[j]=1;
            }
        }
    }

    while(q--)
    {
        int x;
        cin>>x;
        vi pf=distinctPF(x);
        bool isPossible=false;
        for(int i=0;i<pf.size();i++)
        {
            for(int j=i;j<pf.size();j++)
            {
                int product=pf[i]*pf[j];
                if(i==j && x%product!=0)
                {
                    continue;
                }
                int toRemove=x/product;
                if(canRemove[toRemove]==1 || toRemove==1)
                {
                    isPossible=true;
                    break;
                }
            }
            if(isPossible) break;
        }

        std::cout<<(isPossible?"YES":"NO")<<endl;
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

