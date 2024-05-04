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



void mergeArr(int arr[],int l,int mid,int h)
{
    int B[1000];
    int i=l;
    int j=mid+1;
    int k=l;

    while(i<=mid && j<=h)
    {
        if(arr[i]<arr[j])
        {
            B[k++]=arr[i++];
        }
        else
        {
            B[k++]=arr[j++];
        }
    }
    for(;i<=mid;i++)
    {
        B[k++]=arr[i];
    }
    for(;j<=h;j++)
    {
        B[k++]=arr[j];
    }

    for(int i=l;i<=h;i++)
    {
        arr[i]=B[i];
    }

}

void mergeSort(int arr[],int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,h);
        mergeArr(arr,l,mid,h);
    }
}
void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)   
    {
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    give(arr,n);
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

