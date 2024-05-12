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

const int N=1e3+10;
int val[N][N];
int vis[N][N];
int lvl[N][N];
int n,m;

vector<pair<int,int>>movements={
    {0,1},
    {0,-1},
    {1,0},
    {-1,0},
    {1,1},
    {1,-1},
    {-1,-1},
    {-1,1}
};

bool isValid(int x,int y)
{
    return x>=0 && y>=0 && x<n  && y<m;
}

void reset()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            vis[i][j]=0;
            lvl[i][j]=INF;
        }
    }
}

int bfs()
{
    int mx=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(val[i][j]>mx)
            {
                mx=val[i][j];
            }
        }
    }

    queue<pair<int,int>>q;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(val[i][j]==mx)
            {
                q.push({i,j});
                lvl[i][j]=0;
                vis[i][j]=1;
            }
        }
    }
    int ans=0;
    while(!q.empty())
    {
        auto v=q.front();
        int v_x=v.first;
        int v_y=v.second;
        q.pop();

        for(auto movement:movements)
        {
            int child_x=movement.fr+v_x;
            int child_y=movement.sc+v_y;
            if(!isValid(child_x,child_y)) continue;
            if(vis[child_x][child_y]) continue;
            q.push({child_x,child_y});
            lvl[child_x][child_y]=lvl[v_x][v_y]+1;
            vis[child_x][child_y]=1;
            ans=max(ans,lvl[child_x][child_y]);
        }


    }
    return ans;

}

void solve()
{
    reset();
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>val[i][j];
        }
    }
    cout<<bfs()<<endl;
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

