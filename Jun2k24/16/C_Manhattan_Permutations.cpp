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

void super(int test, int totTest)
{
    int n, k;
    cin >> n >> k;

    int possible;
    int firstTerm = n - 1;
    int NoOfterms = n / 2;
    int d = -2;

    possible = (NoOfterms*(2 * firstTerm + (NoOfterms - 1) * d));



    if(k > possible || (k&1)){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        vector<int> ans(n);
        iota(ans.begin(), ans.end(), 1ll);
        
        
        int st = 0;
        int N = n;
        while (k > (N - 1) * 2) {
            swap(ans[st], ans[n - st - 1]);  
            k -= (N - 1) * 2;
            N -= 2;
            st++;
        }

        k /= 2;
        swap(ans[st], ans[st + k]);

        for(auto &x : ans)
            cout << x << " ";
        cout << endl;
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
