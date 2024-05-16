// Problem Link -> https://codeforces.com/problemset/problem/1895/C

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
#define int long long
#define vll vector<int>
#define vbb vector<bool>
#define vss vector<string>
#define vpp vector<pair<int, int>>

typedef long long ll;
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

void super(int test)
{
    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }

    map<int, int> m[6];

    for (int i = 0; i < n;i++){
        int sum = 0;
        for (int j = 0; j < a[i].size();j++){
            sum += (a[i][j] - '0');
        }
        m[a[i].size()][sum]++;
    }

    int ans = 0;
    for (int i = 0; i < n;i++){
        int sum = 0;
        for (int j = 0; j < a[i].size(); j++){
            sum += (a[i][j] - '0');
        }

        int sum2 = 0;
        for (int j = 0; j < a[i].size(); j++){
            sum2 += (a[i][j] - '0');
            if(j + 1 > a[i].size() - j - 1){
                ans += m[j + 1 - (int)a[i].size() + j + 1][2 * sum2 - sum];
            }
        }
        sum2 = 0;
        for (int j = 0; j < a[i].size(); j++)
        {
            sum2 += (a[i][a[i].size()- 1 -j] - '0');
            if(j + 1 > a[i].size() - j - 1){
                ans += m[j + 1 - (int)a[i].size() + j + 1][2 * sum2 - sum];
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
    // cin >> testcases;

    int test = 1;
    while (testcases--)
    {
        super(test++);
    }

    return 0;
}
