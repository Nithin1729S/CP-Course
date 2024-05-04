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

const int N=1e5+10;
int hsh[26][N]; // Note the dimension change

void solve()
{
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<N;j++)
        {
            hsh[i][j]=0;
        }
    }

    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    
    for(int i=0;i<n;i++)
    {
        hsh[s[i]-'a'][i+1]++; // Note the dimension change
    }
    
    for(int i=0;i<26;i++)
    {
        for(int j=1;j<=n;j++)
        {
            hsh[i][j]+=hsh[i][j-1]; // Note the dimension change
        }
    }
    

    while(q--)
    {
        int l,r;
        cin>>l>>r;
        
        int oddCount=0;
        for(int i=0;i<26;i++)
        {
            int charCount=hsh[i][r]-hsh[i][l-1]; // Note the dimension change
            if(charCount%2!=0) oddCount++;
        }
        if(oddCount>1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }

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
