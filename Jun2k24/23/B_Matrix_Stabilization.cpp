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

void super(int test, int totTest)
{
    int n, m;
    cin >> n >> m;

    int MA = 1e9 + 5;
    vector<vector<int>> a(n + 2, vector<int>(m + 2, MA));
    for (int i = 0; i < n ;i++){
        for (int j = 0; j < m;j++){
            cin >> a[i][j];
        }
    }


    for (int i = 1; i <= n ;i++){
        for (int j = 1; j <= m;j++){
            int u, v, w, x;
            u = v = w = x = MA;
            int cnt = 0;
            if (a[i][j] > a[i - 1][j] || a[i - 1][j] == MA)
            {
                cnt++;
            }
            if(a[i][j] > a[i+ 1][j] || a[i + 1][j] == MA){
                cnt++;

            }
            if(a[i][j] > a[i][j-1]  || a[i][j-1] == MA){
                cnt++;

            }
            if(a[i][j] > a[i][j + 1] || a[i][j + 1] == MA){
                cnt++;

            }

            if(cnt == 4){
                int cur = 0;
                if(a[i][j - 1] != MA){
                    cur = max(cur, a[i][j - 1]);
                }
                if(a[i][j + 1] != MA){
                    cur = max(cur, a[i][j + 1]);
                }
                if(a[i-1][j] != MA){
                    cur = max(cur, a[i-1][j]);
                }
                if(a[i+ 1][j] != MA){
                    cur = max(cur, a[i + 1][j]);
                }
                a[i][j] = cur;
            }
        }
    }

    for (int i = 0; i < n ;i++){
        for (int j = 0; j < m;j++){
            cout<<a[i][j]<<" ";
        }
    cout << endl;
    }
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
