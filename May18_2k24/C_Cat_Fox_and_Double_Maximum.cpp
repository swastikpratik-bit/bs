// Problem Link -> https://codeforces.com/contest/1973/problem/C

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

void super(int test)
{
    int n;
    cin >> n;

    vector<int> a(n);
    int one_ind = -1;
    for (int i = 0; i < n;i++){
        cin >> a[i];
        if(a[i]== 1)
            one_ind = i + 1;
    }

    vector<int> q(n), vis(n+ 1);

    for (int i = one_ind&1; i < n;i += 2)
    {
        q[i] = (n + 2 - a[i]);
        vis[n + 2 - a[i]] = 1;
    }

    vector<pair<pair<int,int>, int>> vp;
    for (int i = 0; i < n;i++){
        vp.push_back({{a[i], q[i]}, i});
    }

    sort(vp.rbegin(), vp.rend());
    int st = 1;
    for (int i = 0; i < n; i++)
    {
        if(vp[i].first.second == 0){
            while(vis[st]){
                st++;
            }
            vis[st] = 1;
            vp[i].first.second = st;
        }
    }

    for (int i = 0; i < n;i++){
        q[vp[i].second] = vp[i].first.second;
    }

    for (int i = 0;i < n;i++){
        cout << q[i] << " \n"[i == n - 1];
    }
    
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
