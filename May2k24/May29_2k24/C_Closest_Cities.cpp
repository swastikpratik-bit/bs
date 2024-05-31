// Problem Link -> https://codeforces.com/problemset/problem/1922/C

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

//--------------------------------- DEBUGER ----------------------------------------

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

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
    for(auto & x: a)
        cin >> x;

    vector<int> costLR(n) ,costRL(n), preLR(n) , preRL(n);
    costLR[0] = 0;
    costLR[1] = 1;
    for (int i = 1; i < n - 1; i++)
    {

        if(a[i + 1] - a[i] < a[i] - a[i- 1]){
            costLR[i+ 1] = 1;
        }
        else{
            costLR[i+ 1] = a[i + 1] - a[i];
        }
    }
    costRL[n-1] = 0;
    costRL[n- 2] = 1;
    for (int i = n - 2; i >  0 ; i--)
    {

        if(a[i + 1] - a[i] > a[i] - a[i- 1]){
            costRL[i - 1] = 1;
        }
        else{
            costRL[i - 1] = a[i] - a[i -1];
        }
    }

    preLR[0] = 0;
    for (int i = 1; i < n;i++){
        preLR[i] = preLR[i - 1] + costLR[i];
    }
    preRL[n-1] = 0;
    for (int i = n-2; i >=0 ;i--){
        preRL[i] = preRL[i + 1] + costRL[i];
    }

    // debug(costLR);
    // debug(costRL);
    // debug(preLR);
    // debug(preRL);
    int q;
    cin >> q;
    for (int i = 0; i < q;i++){
        int x, y;
        cin >> x >> y;

        if(y > x){
            cout << preLR[y - 1] - preLR[x - 1] << endl;
        }
        else{
            cout << preRL[y - 1] - preRL[x - 1] << endl;
        }
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
