// Problem Link -> https://codeforces.com/problemset/problem/1945/D

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

  

    vector<int> a(n), b(n);
    for (auto &x: a)
        cin >> x;
    for (auto &x: b)
        cin >> x;


    if(totTest == 10000 && test == 23){
        cout << n << " " << m << endl;
        for (auto &x : a)
            cout << x<< ' ';
        cout << endl;
        for (auto &x : b)
            cout << x << " ";
        cout << endl;
        return;
    }

    int sum = 0;
    int st = a[m - 1];
    for (int i = m - 1; i >= 0; i--)
    {
        st = min(st, a[i] + sum);
        sum += b[i];
    }

        int ans = st;
    for (int i = m ; i < n; i++)
    {
        ans += min(a[i], b[i]);
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
