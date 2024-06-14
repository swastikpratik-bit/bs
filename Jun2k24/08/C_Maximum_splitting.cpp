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

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

vector<int> divisors(int n) 
{
    vector<int> div;
    for (int i = 1; i * i <= n;i++){
        if(n%i== 0){
            div.push_back(i);
            if((n/i) != i){
                div.push_back(n / i);
            }
        }
    }
    sort(div.begin(), div.end());
    return div;
}

void super(int test, int totTest)
{
    vector<int> ans(16, -1), val = {4,6,9};
    ans[0] = 0;
    for (int i = 1; i < 16;i++){
        for (int j = 0; j < 3;j++){
            if(i >= val[j] && ans[i - val[j]] != -1){
                ans[i] = max(ans[i], ans[i - val[j]] + 1);
            }
        }
    }

    int n;
    cin >> n;

    for (int i = 0; i < n;i++){
        int x;
        cin >> x;

        if(x < 16){
            cout << ans[x] << endl;
        }
        else{
            int cur = (x - 16) / 4 + 1;
            cout << cur + ans[x - 4 * cur] << endl;
        }
    }
}

//------------------------- MAIN -------------------------------------
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcases = 1;
    // cin >> testcases;
    int totTest = testcases;

    int test = 1;
    while (testcases--)
    {
        super(test++, totTest);
    }

    return 0;
}
