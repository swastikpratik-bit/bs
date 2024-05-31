// Problem Link -> https://codeforces.com/problemset/problem/1896/C

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
    int n, x;
    cin >> n >> x;

    vector<pair<pair<int,int> , int>> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i].first.first;
        a[i].second = i;
    }

    vector<int> b(n);
    for(auto &x : b)
        cin >> x;
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());

    int pt = 0;
    for (int i = x - 1; i >= 0; i--)
    {
        a[i].first.second = b[x-1-i];
    }
    int last = n - 1;
    for (int i = x; i < n; i++)
    {
        a[i].first.second = b[last--];
    }

    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++)
    {
        B[a[i].second] = a[i].first.second;
        A[a[i].second] = a[i].first.first;
    }

    int cnt = 0;
    for (int i = 0; i < n;i++){
        if(A[i] > B[i])
            cnt++;
    }

    if(cnt == x){
        cout << "YES" << endl;
        for (int i = 0; i < n;i++){
            cout << B[i] << " \n"[i == n - 1];
        }
    }
    else{
        cout << "NO" << endl;
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