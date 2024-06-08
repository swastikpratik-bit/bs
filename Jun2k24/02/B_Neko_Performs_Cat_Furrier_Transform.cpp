// Problem Link -> https://codeforces.com/problemset/problem/1152/B

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

void super(int test, int totTest)
{
    int x;
    cin >> x;


    vector<int> ans;
    int f = 1;
    int cnt = 0;
    while (set_bits(x + 1) != 1)
    {
        if(f){
            int cur = -1;
            for (int bit = log2l(x); bit >= 0;bit--){
                if(x&(1ll<<bit)){

                }
                else{
                    cur = bit+ 1;
                    break;
                }
            }

            ans.push_back(cur);
            int y = (1 << cur) - 1;
            // cout << y << endl;
            x = (x ^ ((1 << cur) - 1));
            
        }
        else{
            x++;
        }
        cnt++;
        f ^= 1;
    }
    cout << cnt << endl;
    for (auto &x : ans)
        cout << x << " ";
    cout << endl;
}

//------------------------- MAIN -------------------------------------
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcases = 1;
    // cin >> testcases;
    int totTest = testcases;

    int test = 1;
    while (testcases--)
    {
        super(test++, totTest);
    }

    return 0;
}
