// Problem Link -> https://codeforces.com/contest/1921/problem/D

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
    int n, m;
    cin >> n>>m;
    vector<int> a(n), b(m);
    for(auto &x : a)
        cin >> x;
        
    for(auto &x : b)
        cin >> x;

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    int ans = 0;
    int ind = -1;
    for (int i = 0; i < n; i++)
    {
        int x = abs(a[i] - b[m - n + i]);
        int y = abs(a[i] - b[i]);
      
        if (abs(a[i] - b[m - n + i]) > abs(a[i] - b[i]))
        {
            ind = i;
            break;
        }
        ans += abs(a[i] - b[i]);
        
    }
    
    

    if(ind == -1){
        cout << ans << endl;
        return;
    }
    for (int i = ind; i < n;i++){
        ans += abs(a[i] - b[i+ (m - n)]);
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

    int test = 1;
    while (testcases--)
    {
        super(test++);
    }

    return 0;
}
