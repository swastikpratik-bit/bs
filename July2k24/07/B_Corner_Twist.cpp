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

bool chk(vector<vector<int>> &a ,vector<vector<int>> &b ){
    for (int i = 0; i < a.size();i++){
        for (int j = 0; j < a[0].size();j++){
            if(a[i][j] != b[i][j])
                return false;
        }
    }
    return true;
}

void super(int test, int totTest)
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));

    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }

    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            char c;
            cin >> c;
            b[i][j] = c - '0';
        }
    }

    for (int i = n - 1; i > 0; --i) {
        for (int j = m - 1; j > 0; --j) {
            if (a[i][j] != b[i][j]) {
                int need = (b[i][j] - a[i][j]) % 3;
                if(need < 0)
                    need += 3;
                a[i][j] = b[i][j];
                a[i][j - 1] = (a[i][j - 1] + 2 * need) % 3;
                a[i - 1][j - 1] = (a[i - 1][j - 1] + need) % 3;
                a[i - 1][j] = (a[i - 1][j] + 2 * need) % 3;
            }
        }
    }

    cout << (chk(a, b) ? "YES" : "NO" )<< endl;
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
