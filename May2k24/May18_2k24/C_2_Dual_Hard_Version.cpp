// Problem Link -> https://codeforces.com/contest/1855/problem/C2

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

vector<pair<ll, ll>> allPositive(vector<ll> arr)
{
    ll n = arr.size();
    ll mx = 0;
    ll in = 0;
    ll mn = 0;
    ll in2 = 0;
    for (ll i = 0; i < n; i++)
    {
        if (arr[i] > mx)
        {
            mx = arr[i];
            in = i;
        }
        if (arr[i] < mn)
        {
            mn = arr[i];
            in2=i;
        }
    }
    vector<pair<ll, ll>> ans;
    while (arr[in] < (abs(mn)))
    {
        arr[in] += arr[in];
        ans.push_back({in + 1, in + 1});
    }
 
    for (ll i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            ans.push_back({i + 1, in + 1});
        }
    }
 
    for (ll i = 1; i < n; i++)
    {
        ans.push_back({i + 1, i});
    }
 
    return ans;
}


vector<pair<ll, ll>> allNegative(vector<ll> arr)
{
    ll n = arr.size();
    ll mx = 0;
    ll in = 0;
    ll mn = 0;
    ll in2 = 0;
    for (ll i = 0; i < n; i++)
    {
        if (arr[i] > mx)
        {
            mx = arr[i];
            in = i;
        }
        if (arr[i] < mn)
        {
            mn = arr[i];
            in2=i;
        }
    }
    vector<pair<ll, ll>> ans;
 
    while (abs(arr[in2])< arr[in])
    {
        arr[in2] += arr[in2];
        ans.push_back({in2+1, in2+1});
    }
 
    for (ll i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            ans.push_back({i+1, in2+1});
        }
    }
 
    for (ll i = n; i >= 2; i--)
    {
        ans.push_back({i - 1, i});
    }
 
    return ans;
}



void op(vector<pair<int,int>> &vp){
    cout << vp.size() << endl;
    for (auto [x, y] : vp)
    {
        cout << x << " " << y << endl;
    }
}

void super(int test)
{
    int n;
    cin >> n;

    vector<int> a(n);
    int neg = 0, pos = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pos += (a[i] >= 0);
        neg += (a[i] <= 0);
    }

    if(is_sorted(a.begin(),a.end())){
        cout << 0 << endl;
        return;
    }

    if (pos == n)
    {
        cout << n - 1 << endl;

        for (ll i = 2; i <= n; i++)
        {
            cout << i << " " << i - 1 << endl;
        }
        return;
    }

    if (neg == n)
    {

        cout << n - 1 << endl;
        for (ll i = n; i >= 2; i--)
        {
            cout << i - 1 << " " << i << endl;
        }
        return;
    }

    vector<pair<int, int>> ans;
    ans = allPositive(a);

    if(ans.size() <= 31 ){
        op(ans);
        return;
    }

    ans.clear();
    ans= allNegative(a);

    // debug(a);
    op(ans);

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
