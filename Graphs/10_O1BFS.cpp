#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long >
#define fr first
#define sc second
#define INF INT_MAX
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

const int N=1e5+10;
vector<pair<int,int>>g[N];
vi lvl(N,INF);
int n,m;

int bfs(int src)
{
    deque<int>q;
    q.push_back(src);
    lvl[1]=0;
    while(!q.empty())
    {
        int curr_v=q.front();
        q.pop_front();

        for(auto &child:g[curr_v])
        {
            int child_v=child.fr;
            int wt=child.sc;
            if(lvl[curr_v]+wt<lvl[child_v])
            {
                lvl[child_v]=lvl[curr_v]+wt;
                if(wt==1)
                {
                    q.push_back(child_v);
                }
                else
                {
                    q.push_front(child_v);
                }
            }
        }
        
    }
    return lvl[n]==INF ? -1:lvl[n];



}

void solve()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x==y) continue;
        g[x].pb({y,0});
        g[y].pb({x,1});
    }
    cout<<bfs(1)<<endl;
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

