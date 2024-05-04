#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long >
#define fr first
#define sc second
#define INF LLONG_MAX
#define MOD 1000000007
#define pii pair<int,int>
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define clr(x) memset(x,0,sizeof(x))
#define sortUni(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define test int t;cin>>t;while(t--)
#define take(a,n) vi a(n); for(int i=0;i<n;i++) cin >> a[i];
#define give(a,n) for(int i=0;i<n;i++) {cout << a[i] << ' ';}cout << endl;

void solve()
{
    int n;
    cin>>n;
    vector<int>masks(n,0);
    for(int i=0;i<n;i++)   
    {
        int num_workers;
        int mask=0;
        cin>>num_workers;
        for(int j=0;j<num_workers;j++)
        {
            int day;
            cin>>day;
            mask=(mask|(1<<day));
        }
        masks[i]=mask;
    }
    
    int max_days=0;
    int person1=-1;
    int person2=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int intersection=(masks[i]&masks[j]);
            int common_days=__builtin_popcount(intersection);
            if(common_days>max_days)
            {
                max_days=common_days;
                person1=i;
                person2=j;
            }
        }
    }
    cout<<person1<<" "<<person2<<" "<<max_days<<endl;
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

