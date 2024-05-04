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

bool isVowel(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
    {
        return true;
    }
    else
    {
        return false;
    }
}

vector<string>subsets(string s)
{
    int n=(1<<s.size());
    vector<string>ans;
    for(int mask=0;mask<n;mask++)
    {
        string subset;
        for(int bit=0;bit<s.size();bit++)
        {
            if((mask&(1<<bit))!=0)
            {
                subset.pb(s[bit]);
            }
        }
        if(subset.size()) ans.pb(subset);
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    string str[n];
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
    }

    unordered_map<string,int>hsh;
    for(int i=0;i<n;i++)
    {
        set<char>distinct_vowels;
        for(auto ch:str[i])
        {
            if(isVowel(ch)) distinct_vowels.insert(ch);
        }
        string distinct_vowels_string;
        for(auto ch:distinct_vowels)
        {   
            distinct_vowels_string.pb(ch);
        }

        vector<string>all_subsets=subsets(distinct_vowels_string);

        for(auto it:all_subsets)
        {
            hsh[it]++;
        }

    }
    // for(auto it:hsh)
    // {
    //     cout<<it.fr<<" "<<it.sc<<endl;
    // }
    ll ans=0;
    for(auto &pr:hsh)
    {
        if(pr.sc<3) continue;
        ll ct=pr.sc;
        ll ways=(ct*(ct-1)*(ct-2))/6;
        if(pr.first.size()%2==0)
        {
            ans-=ways;
        }
        else ans+=ways;
    }
    cout<<ans<<endl;

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

