// Problem Link -> 

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define leadingzero __builtin_clzll
#define trailingzero __builtin_ctzll
#define bitsParity __builtin_parity
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
// #define int long long
#define vll vector<int>
#define vbb vector<bool>
#define vss vector<string>
#define vpp vector<pair<int, int>>

// typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

const int MOD = 1000000007;


//------------------------------ SOLVE -------------------------------------
/*
        --> READ PROPERLY (READ AGAIN)
        --> THINK > FORMULATE > STRUCTURE CODE > CODE
        --> Check variables, overflows
        --> DEBUG
        --> SUBMIT
 
        * special cases (n=1?)
        * do something instead of nothing and stay organized
        * WRITE STUFF DOWN
        * DON'T GET STUCK ON ONE APPROACH
 
        * try to apply brute force first > 
        * think greedy > 
        * Don't Overthink about complexity >
        * Use pen-copy > 
*/

void super(int test, int totTest)
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto &x : a)
        cin >> x;

    vector<vector<int>> cnt(200, vector<int>(n + 1));
    vector<vector<int>> pos(200);

    for (int i = 0;i < n ;i++){
        for (int el = 0; el < 200; el++){
            cnt[el][i + 1] = cnt[el][i];
        }
        cnt[a[i] - 1][i + 1]++;
        pos[a[i] - 1].push_back(i);
    }

    int ans = 0;

    for (int el = 0; el < 200;el++){
        ans = max(ans, (int)pos[el].size());
        for (int i = 0; i < pos[el].size() / 2;i++){
            int left = pos[el][i] + 1;
            int right = pos[el][pos[el].size() - i - 1];

            for (int cur = 0; cur < 200;cur++){
                int sum = cnt[cur][right] - cnt[cur][left];
                ans = max(ans, (i + 1) * 2 + sum);
            }
        }
    }
    cout << ans << endl;
}

//------------------------- MAIN -------------------------------------
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
