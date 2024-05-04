#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define fr first
#define sc second
#define INF LLONG_MAX
#define MOD 1000000007
#define pii pair<int,int>
#define int long long
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define clr(x) memset(x,0,sizeof(x))
#define sortUni(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define f0(i,n)  for(int i=0;i<(int)n;i++)
#define f1(i,n)  for(int i=1;i<=(int)n;i++)
#define test int t;cin>>t;while(t--)
#define take(a,n) vi a(n); f0(i,n) cin >> a[i];
#define give(a,n) f0(i,n){cout << a[i] << ' ';}cout << endl;

vector<string>valid;

void generate(string &s,int open,int close)
{
    if(open==0 && close==0)
    {
        valid.push_back(s);
    }

    if(open>0)
    {
        s.push_back('(');
        generate(s,open-1,close);
        s.pop_back();
    }

    if(close>0 )
    {
        if(open<close)
        {
            s.push_back(')');
            generate(s,open,close-1);
            s.pop_back();
        }
    }
}
void solve()
{
    int n;
    cin>>n;
    string s;
    generate(s,n,n);   
    for(auto it:valid) cout<<it<<endl;
    
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

