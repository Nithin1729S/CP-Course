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
vector<int>g[N];
int vis[8][8];
int lvl[8][8];

int getX(string s)
{
    return s[0]-'a';
}

int getY(string s)
{
    return s[1]-'1';
}

bool isValid(int x,int y)
{
    return x>=0 && y>=0 && x<8 && y<8;
}

vector<pair<int,int>>movements={
    {-1,2},{1,2},
    {-1,-2},{1,-2},
    {2,-1},{2,1},
    {-2,-1},{-2,1},
};

void reset()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            lvl[i][j]=INF;
            vis[i][j]=0;
        }
    }
}
int bfs(string src,string dest)
{
    int srcX=getX(src);
    int srcY=getY(src);
    int destX=getX(dest);
    int destY=getY(dest);
    queue<pair<int,int>>q;
    q.push({srcX,srcY});
    vis[srcX][srcY]=1;
    lvl[srcX][srcY]=0;

    while(!q.empty())
    {   
        pair<int,int>v=q.front();
        q.pop();
        int x=v.first;
        int y=v.second;
        
        for(auto movement:movements)
        {
            int childX=movement.first+x;
            int childY=movement.second+y;
            if(!isValid(childX,childY)) continue;
            if(!vis[childX][childY])
            {
                q.push({childX,childY});
                lvl[childX][childY]=lvl[x][y]+1;
                vis[childX][childY]=1;
            }
        }
        if(lvl[destX][destY]!=INF){
            break;
        }
    }

    return lvl[destX][destY];

}
void solve()
{
    reset();
    string a,b;
    cin>>a>>b;
    cout<<bfs(a,b)<<endl;
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

