#include <bits/stdc++.h>

using namespace std;

#define set_bits __builtin_popcountll
#define leadingzero __builtin_clzll
#define trailingzero __builtin_ctzll
#define bitsParity __builtin_parity
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
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

const int MOD = 1000000007;
int nCr(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || n == r) return 1;

    double res = 0;
    for (int i = 0; i < r; i++) {
    
        res += log(n-i) - log(i+1);
    }

    return (int)round(exp(res));
}

int modMul (int a , int b){
    return (a % MOD * b % MOD) % MOD;
}
void super(int test, int totTest)
{
    int n, k;
    cin >> n >> k;
    int a[n];
    int z = 0;
    int o = 0;
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
        z += (a[i] == 0);
        o += (a[i] == 1);
    }

    int med = (k / 2);
   
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0) {
            int pre_c = pre[i] + z;
            int later_one = pre[n] - pre[i + 1];
            debug(pre_c);
            int cur = modMul(nCr(pre_c, med) , nCr(later_one, med));
            ans = (ans + cur) % MOD;
        }
    }
    cout << ans << endl;
}

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