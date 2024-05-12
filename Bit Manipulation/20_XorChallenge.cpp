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

void solve()
{
    int c;
    cin>>c;
    int a=0;
    int b=0;
    vector<int>set_bits;
    int bit_ct=(int)log2(c)+1;
    for(int i=0;i<bit_ct;i++)
    {
        if(c&(1<<i) )
        {
            set_bits.pb(i);
        }
        else
        {
            a=a|(1<<i);  //set ith bit of a as 1;
            b=b|(1<<i);  //same here 
        }
    }
    int sz=1<<set_bits.size();
    ll ans=-1;
    for(int mask=0;mask<sz;mask++)
    {
        int a_copy=a;
        int b_copy=b;
        for(int j=0;j<set_bits.size();j++)
        {
            if(mask&(1<<j))
            {
                a_copy|=(1<<set_bits[j]);
            }
            else
            {
                b_copy|=(1<<set_bits[j]);

            }
        }
        ans=max(ans,a_copy*1ll*b_copy);
    }
    cout<<ans;


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

