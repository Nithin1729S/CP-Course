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


vector<int>NGE(vector<int>arr)
{
    vi res(arr.size());
    stack<int>stk;
    for(int i=0;i<arr.size();i++)
    {
        if(stk.empty())
        {
            stk.push(i);
        }
        else
        {
            while(!stk.empty() && arr[stk.top()]<arr[i])
            {
                int ele=stk.top();stk.pop();
                res[ele]=arr[i];
            }
            stk.push(i);
        }
    }
    while(!stk.empty())
    {
        int ele=stk.top();stk.pop();
        res[ele]=-1;
    }
    return res;
}
void solve()
{
    int n;
    cin>>n;
    take(arr,n);
    vi res=NGE(arr);
    give(res,n);


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

