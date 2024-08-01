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
    int n , x ;
    cin>>n>>x;

    int ans = 0;
    int ma = 0;
    int mi = 1e9;
    vector<int> a(n);
    for(int i = 0 ;i < n;i++){
        cin>>a[i];
        ma = max(ma , a[i]);
        mi = min(mi , a[i]);
    }
    for(int i = 1 ;i < n;i++){
        ans += abs(a[i] - a[i -1]);
    }

    if(mi > 1){
        int NearMin = 2*(mi - 1);
        int L = a[0] - 1;
        int R = a[n - 1] - 1;
        ans += min({NearMin , L , R});
    }


    if(ma < x){
        int NearMax = 2*(x - ma);
        int L = x - a[0];
        int R = x - a[n - 1];
        ans += min({NearMax , L , R});
    }

    cout<<ans<<endl;
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