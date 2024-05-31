// Problem Link -> https://codeforces.com/contest/1547/problem/D

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

    vector<int> a(n), ans(n);
    for(auto & x: a)
        cin >> x;

    for (int i = 1; i < n;i++){

        if((a[i-1]&a[i]) != a[i-1]){
            int cur = 0;
            for (int bit = 0; bit < 31;bit++){
                int f = ((a[i - 1]) & (1ll << bit));
                int s = ((a[i]) & (1ll << bit));
                if (f && !s)
                {
                    cur |= (1 << bit);
                }
            }
            ans[i] = cur;
            a[i] ^= cur;
        }
    }

    for (int i = 0; i < n;i++){
        cout << ans[i] << " \n"[i == n - 1];
    }
}

//------------------------- MAIN -------------------------------------
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcases = 1;
    cin >> testcases;

    int test = 1;
    while (testcases--)
    {
        super(test++);
    }

    return 0;
}
