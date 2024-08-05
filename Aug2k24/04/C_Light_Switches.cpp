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
    int n , k;
    cin>>n>>k;

    vector<int>a(n) ;
    int ma = 0;
    for(auto&x : a){
        cin>>x;
        ma = max(ma , x);
    }
    int ans = -1;
    for(int res = ma ;res < ma + k ;res++){
        int possible = 1;
        for(int j = 0;j < n;j++){
            int cur = res - a[j];
            cur %= 2*k;
            if(cur >= k){
                possible = 0;
                break;
            }
        }
        if(possible){
            cout<<res<<endl;
            return;
        }
    }

    cout<<ans<<endl;
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