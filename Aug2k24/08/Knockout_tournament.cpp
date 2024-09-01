#include <bits/stdc++.h>

using namespace std;

#define set_bits __builtin_popcountll
#define leadingzero __builtin_clzll
#define trailingzero __builtin_ctzll
#define bitsParity __builtin_parity
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

const int MOD = 1000000007;


void super(int test, int totTest)
{
    vector<pair<int,int>> a(16);
    for(int i= 0 ;i < 16;i++){
        cin>>a[i].first;
        a[i].second = i;
    }
    sort(rall(a));

    vector<int> ans(16);
    ans[a[0].second] = 4;
    for(int i = 1 ;i <= 8;i++){
        ans[a[i].second] = 3;
    }
    for(int i = 9 ;i <= 12;i++){
        ans[a[i].second] = 2;
    }
    for(int i = 13 ;i <= 14;i++){
        ans[a[i].second] = 1;
    }
    ans[a[15].second] = 0;

    for(auto &x: ans)cout<<x<<" ";
    cout<<endl;







}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcases = 1;
    cin >> testcases;
    int totTest = testcases;

    int test = 1;
    while (testcases--)
    {
        super(test++, totTest);
    }

    return 0;
}