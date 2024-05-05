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

vector<string> summaryRanges(vector<int>& nums) {
        vector<string>res;
        int i=0;
        while(i<nums.size())
        {
            vector<int>v;
            string s;
            if(v.empty()||nums[i]-v.back()>1)
            {
                v.push_back(nums[i]);
                i++;
            }
            else
            {
                s+=to_string(v.front());
                s+=to_string(v.back());
                res.push_back(s);
                v.clear();
                i++;
            }

        }

        return res;

    }

void solve()
{
    vi nums={0,1,2,4,5,7};
    vector<string>ranges=summaryRanges(nums);
    for(auto it:ranges)
    {
        cout<<it<<" ";
    }
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

