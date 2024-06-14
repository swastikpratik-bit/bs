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
vector<bool> primes;
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

void super(int test, int totTest)
{
    int N;
    cin >> N;
    vector<int> cur;
    for (int i = 0; i < primes.size(); i++)
    {
        if(primes[i]){
            cur.push_back(i);
        }
    }

    for (int i = 0; i < cur.size();i++){
        for (int j = 0; j < cur.size();j++){
            if(i != j){
                int a = cur[i] * cur[i];
                int b = cur[j] * cur[j];
                int need = sqrt(N - a - b);
                int k = lower_bound(cur.begin(), cur.end(), need) - cur.begin();

                if(k != j && k != i && k < cur.size()){
                    int c = cur[k] * cur[k];
                    if(a + b + c == N){
                        cout << "YES" << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
}

//------------------------- MAIN -------------------------------------
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcases = 1;
    cin >> testcases;
    int totTest = testcases;
    primes = PrimesTillN(1000);
    int test = 1;
    while (testcases--)
    {
        super(test++, totTest);
    }

    return 0;
}
