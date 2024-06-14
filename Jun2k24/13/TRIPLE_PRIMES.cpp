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
vector<bool> prime(1e5 + 1, 1);
vector<int> primes;
void PrimesTillN(int n)
{
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                prime[j] = 0;
        }
    }

    for (int i = 2; i <= 1e5;i++){
        if(prime[i])primes.push_back(i);
    }
}
void super(int test, int totTest)
{
    int n;
    cin >> n;

    if(n <= 37){
        cout << "NO" << endl;
        return;
    }

    int a = 4;
    n -= a;
    for (auto b : primes)
    {
        int rem = n - b * b;
        if(rem <= 0)
            break;

        int c = sqrt(rem);
        if((c*c != rem) || (c == a) || (!prime[c]) || (c == 2)){
            
        }
        else{
            cout << "YES" << endl;
            return;
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
    PrimesTillN(1e5);
    int test = 1;
    while (testcases--)
    {
        super(test++, totTest);
    }

    return 0;
}
