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
    int n;
    cin >> n;
    vector<vector<int>> A(n);
    vector<int> d(n);

    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    for (int e = 0; e < n - 1; ++e) {
        int x, y;
        cin >> x >> y;
        A[x - 1].push_back(y - 1);
        A[y - 1].push_back(x - 1);
    }

    int ind = min_element(d.begin(), d.end()) - d.begin();
    vector<bool> vis(n, false);
    vector<int> ans;
    vis[ind] = true;
    ans.push_back(ind);
    deque<int> bfs;
    bfs.push_back(ind);

    while (!bfs.empty()) {
        int i = bfs.front();
        bfs.pop_front();
        for (int j : A[i]) {
            if (!vis[j]) {
                vis[j] = true;
                ans.push_back(j);
                bfs.push_back(j);
            }
        }
    }

    cout << ans.size() - 1 << endl;
    for (int i = ans.size() - 1; i > 0; i--)
    {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
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
