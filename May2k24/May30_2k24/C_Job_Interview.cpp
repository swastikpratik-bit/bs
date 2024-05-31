// Problem Link -> https://codeforces.com/contest/1976/problem/C

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

    vector<int> a(n + m + 1) , b(n + m +1);

    for (int i = 0; i < n + m + 1;i++){
        cin >> a[i];
    }
    for (int i = 0; i < n + m + 1;i++){
        cin >> b[i];
    }

    int sumA = 0, sumB = 0, cA = 0, cB = 0;
    vector<int> vis1(n + m + 1) , vis2(n+ m + 1);

    for (int i = 0; i < n + m + 1;i++){
        if(a[i] > b[i] && cA <= n){
            sumA += a[i];
            cA++;
            vis1[i] = 1;
        }
        else if(a[i] < b[i] && cB < m){
            sumA+= b[i];
            cB++;
            vis1[i] = 0;

        }
        else if(cA <= n){
            sumA+= a[i];
            cA++;
            vis1[i] = 1;
        }
        else{
            sumA+= b[i];
            cB++;
            vis1[i] = 0;
        }
    }

    cA = 0, cB = 0;
     for (int i = 0; i < n + m + 1;i++){

        if(a[i] < b[i] && cB <= m){
            sumB+= b[i];
            cB++;
            vis2[i] = 0;
        }
        else if(a[i] > b[i] && cA < n){
            sumB += a[i];
            cA++;
            vis2[i] = 1;
        }
        else if(cB <= m){
            sumB+= b[i];
            cB++;
            vis2[i] = 0;
        }
        else{
            sumB+= a[i];
            cA++;
            vis2[i] = 1;
        }
    }

    // vector<int> 
    for (int i = 0; i < n + m + 1;i++){
        int cur = 0;
        if (vis1[i] == 1)
        {
            cur =  sumA - a[i];
        }
        else if(vis2[i] == 0){
            cur = sumB - b[i];
        }
        cout << cur << " ";
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
