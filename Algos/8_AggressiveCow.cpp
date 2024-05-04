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
#define take(a,n) vi a(n); f0(i,n) cin >> a[i];
#define give(a,n) f0(i,n){cout << a[i] << ' ';}cout << endl;

const int N=1e5+10;
int n,cows;
int positions[N];

bool canPlaceCows(int minDist)
{
    int cowsCt=cows;
    int lastPos=-1;
    for(int i=0;i<n;i++)
    {
        if((positions[i]-lastPos>=minDist)
        || lastPos==-1)
        {
            cowsCt--;
            lastPos=positions[i];
        }
        if(cowsCt==0) break;
    }
    return cowsCt==0;

}
void solve()
{
    cin>>n>>cows;
    for(int i=0;i<n;i++)
    {
        cin>>positions[i];
    }
    sort(positions,positions+n);
    int lo=0;
    int hi=1e9;
    int mid;
    while(hi-lo>1)
    {
        mid=(hi+lo)/2;
        if(canPlaceCows(mid))
        {
            lo=mid;
        }
        else
        {
            hi=mid-1;
        }
    }
    if(canPlaceCows(hi)) cout<<hi<<endl;
    else cout<<lo<<endl;
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

