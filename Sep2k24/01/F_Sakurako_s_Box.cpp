#include <bits/stdc++.h>

using namespace std;

#define set_bits __builtin_popcountll
#define leadingzero __builtin_clzll
#define trailingzero __builtin_ctzll
#define bitsParity __builtin_parity
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

const int MOD = 1000000007;

int modMul (int a , int b){
    return (a % MOD * b % MOD) % MOD;
}

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

int modInv(int a){
    return binExpRec(a, MOD - 2);
}

int modDiv (int a , int b)  {
    return modMul(a, modInv(b));
}

void super(int test, int Test)
{
    int n;
    cin>>n;

    vector<int> a(n);
    for(auto &x : a)cin>>x;

    int sum = 0  , sumOfSq = 0 ;
    for(int i =0 ;i < n;i++){
        sum = (sum + a[i])%MOD;
        sumOfSq = (sumOfSq + (a[i] * a[i])%MOD)%MOD;
    }

    int P = (sum * sum)%MOD;
    P = (P - sumOfSq + MOD)%MOD;
    int Q = (n*(n - 1))%MOD;
    int ans = modDiv(P, Q);

    cout<<ans<<endl;

}

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