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
const int N = 1e6 + 1;
vector<int> primeFL(N+ 1);
vector<bool> PrimesTillN(int n)
{
    vector<bool> prime(n + 1, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                prime[j] = 0;
        }
    }
    return prime;
}
void pre(){
    primeFL[1] = 1;
    for (int i = 2; i <= N;i++){
        if(!primeFL[i]){
            primeFL[i] = i;
            for (int j = i * i; j <= N; j += i)
            {
                if(!primeFL[j]){
                    primeFL[j] = i;
                }
            }
        }
    }
}

vector<int> same;
void pre2()
{
    for (int i = 2; i <= N;i++){
        if(primeFL[i] == i){
            same.push_back(i);
        }
    }
}

void super(int test, int totTest)
{
    int k;
    cin >> k;

    bool is = primeFL[k] == k;

    cout << is << endl;
    int ans = 0;
    if (is)
    {
        for(auto x : same){
            if(x <= k){
                ans += x * k;
            }
            else{
                break;
            }
        }
    }
    else{
        for(auto x : same){
            if(x <= primeFL[k]){
                ans += x * k;
            }
            else{
                break;
            }
        }
    }

    // cout << ans << endl;
}

//------------------------- MAIN -------------------------------------
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    pre2();
    int testcases = 1;
    cin >> testcases;
    int totTest = testcases;

    // iota(all(vals), 2ll);

    int test = 1;
    while (testcases--)
    {
        super(test++, totTest);
    }

    return 0;
}
