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

 int modMul (int a , int b){
            return (a % MOD * b % MOD) % MOD;
        }
void super(int test, int totTest)
{
    int n;
    cin>>n;

    int ans = 0;
    int bck = 0 ;

    for(int i =1 ;i<= n;i++){
        int here = bck;
        here = (here*2)%MOD;
        here = (here + binExpRec(i - 1, 2))%MOD;
        ans = (ans + (here * binExpRec(2 , n - i)) %MOD)%MOD;
        bck = here;
    }
    
    ans = (ans* 2)%MOD;
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