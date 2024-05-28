// Problem Link -> https://codeforces.com/contest/1660/problem/D

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

vector<int> helper(vector<int> &b){
    int m = b.size();
    vector<int> left(m), right(m);

    left[0] = b[0];
    for (int i = 1; i < m; i++)
    {
        left[i] = left[i - 1] * b[i];
    }

    right[m - 1] = b[m - 1];
    for (int i = m - 2; i >= 0;i--){
        right[i] = right[i + 1] * b[i];
    }

    debug(left);
    debug(right);


    int m1 = 0, ind1 = -1, m2 = 0, ind2 = -1;
    for (int i = 0;i < m; i++){
        if(left[i] > m1){
            m1 = left[i];
            ind1 = i+ 1;
        }
        if(right[i] > m2){
            m2 = right[i];
            ind2 = i+ 1;
        }
    }

    debug(m1);
    debug(m2);
    debug(ind1);
    debug(ind2);
    vector<int> ans;
    if (m1 >= m2)
    {
        ans.push_back(0);
        ans.push_back(m - ind1);
        ans.push_back(m1);
    }
    else{
        ans.push_back(ind2-1);
        ans.push_back(0);
        ans.push_back(m2);
    }

    return ans;
}

void super(int test)
{
    int n;
    cin >> n;

    vector<int> a(n);
    int zero = 0;
    for (auto &x : a){
        cin >> x;
        zero += (x == 0);
    }

    if(zero == 1){
        int ind = -1;
        for (int i = 0; i < n;i++){
            if(a[i] == 0){
                ind = i;
                break;
            }
        }

        vector<int> xx;
        for (int i = ind + 1; i < n; i++)
        {
            xx.push_back(a[i]);
        }
        vector<int> yy;
        for (int i = 0; i < ind; i++)
        {
            yy.push_back(a[i]);
        }

        debug(xx);
        debug(yy);

        vector<int> ans1, ans2;
        if(xx.size()> 0)
            ans1 = helper(xx);
        else
            ans1.assign(3, 0);

        
        if(yy.size()> 0)
            ans2 = helper(yy);
        else
            ans2.assign(3, 0);

        if(ans1[2] >= ans2[2]){
            cout << ans1[0] + ind + 1<< " " << ans1[1] << endl;
        }
        else{
            cout << ans2[0]<< " " << ans2[1] - (n - ind)<< endl;
        }
        return;
    }

    if(zero > 1){
        int ll = 1;
        for (int i = 0; i < n;i++){
            if(a[i] == 0)
                break;
            ll++;
        }

        int rr = 1;
        for (int i = n - 1; i >= 0;i--){
            if(a[i] == 0)
                break;
            rr++;
        }

        vector<int> xx;
        for (int i = ll; i < n - rr;i++){
            xx.push_back(a[i]);
        }

        debug(xx);

        vector<int> ans = helper(xx);
        cout << ans[0] + ll<< " " << ans[1] + rr<< endl;
        return;
    }
    vector<int> ans = helper(a);
    debug(ans)
    cout << ans[0] << " " << ans[1] << endl;
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
