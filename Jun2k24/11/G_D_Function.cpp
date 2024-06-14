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

int binExpRec(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    long long res = binExpRec(a, b / 2);
    if (b & 1)
    {
        // b is odd
        return (a * ((res * res) % MOD)) % MOD;
    }
    else
    {
        // b is even
        return (res * res) % MOD;
    }
}

int DS(int x){
    int sum = 0;

    while(x){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

void super(int test, int totTest)
{
    int L, R, K;
    cin >> L >> R >> K;

    for (int i = pow(10, L); i <= pow(10, R);i++){
        if(DS(i*K) == DS(i)*K){
            cout << i << endl;
        }
    }


    if (K >= 10)
    {
        cout << 0 << endl;
        return;
        }

    int cur = 10ll / K;

    if(10%K)
        cur++;

    int a = binExpRec(cur, R);
    int b = binExpRec(cur, L);
    int ans = (a - b + MOD) % MOD;
    // cout << ans << endl;
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
