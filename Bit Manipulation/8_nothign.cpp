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

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        vector<pair<pair<int,int>, char>> mp;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            mp.push_back({{points[i][0], points[i][1]}, s[i]});
        }

        // Sort based on the absolute value of the largest coordinate
        sort(mp.begin(), mp.end(), [](const pair<pair<int,int>, char>& a, const pair<pair<int,int>, char>& b) {
        int dist_a = a.first.first * a.first.first + a.first.second * a.first.second;
        int dist_b = b.first.first * b.first.first + b.first.second * b.first.second;
        return dist_a > dist_b;
    });

        // Print sorted points along with their letter class
        for(const auto& p : mp) {
            cout << "(" << p.first.first << ", " << p.first.second << "): " << p.second << endl;
        }
        vector<char>alpha;
        for(const auto& p : mp) {
            char c=p.second;
            alpha.push_back(c);
        }
        reverse(alpha.begin(),alpha.end());
        give(alpha,alpha.size());
        std::unordered_set<char> seenChars;
        int count = 0;
        for (char c : alpha) {
        if (seenChars.find(c) != seenChars.end()) {
            break;
        }
        seenChars.insert(c);
        count++;
        }  
        
        cout<<count<<endl;
        return count;
    }
};

void solve()
{
    Solution sol;
    vector<vector<int>> points{{1,1},{-1,-1},{2,-2}};    
    string s="ccd";
    sol.maxPointsInsideSquare(points,s);   
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
