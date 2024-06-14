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

int MA(vector<int> A){
    int val = A[1] - A[0] + 1;
    val *= A[3] - A[2] + 1;
    val *= A[5] - A[4] + 1;
    return val;
}

void super(int test, int totTest)
{
    int x, y, z, k;
    cin >> x >> y >> z >> k;

    int ans = 0;

    
    for (int a = 1; a*a*a <= k; a++) {
        if (k % a == 0) {
            for (int b = 1; b*b <= k / a; b++) {
                if ((k / a) % b == 0) {
                    int c = k / (a * b);
                    if (a <= x && b <= y && c <= z) {
                        vector<int> cur = {a, x, b, y, c, z};
                        ans = max(ans, MA(cur));
                    }
                    if (b <= x && a <= y && c <= z) {
                        vector<int> cur = {b, x, a, y, c, z};
                            ans = max(ans, MA(cur));
                    }
                    if (b <= x && c <= y && a <= z) {
                        vector<int> cur = {b, x, c, y, a, z};
                                ans = max(ans, MA(cur));

                    }
                    if (c <= x && b <= y && a <= z) {
                        vector<int> cur = {c, x, b, y, a, z};
                        ans = max(ans, MA(cur));
                    }
                    if (a <= x && c <= y && b <= z) {
                        vector<int> cur = {a, x, c, y, b, z};
                        ans = max(ans, MA(cur));
                    }
                    if (c <= x && a <= y && b <= z) {
                        vector<int> cur = {c, x, a, y, b, z};
                            ans = max(ans, MA(cur));

                    }
                }
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
