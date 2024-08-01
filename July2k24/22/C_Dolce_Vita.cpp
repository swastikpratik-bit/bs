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
    int n , x;
    cin>>n>>x;

    vector<int> a(n);
    for(auto &x: a)cin>>x;

    auto days = [](int val , int x ,int i){
        int low = 0, high = 1e9 + 3, D = 0;

        while(high >= low){
            int mid = (high + low)/2;

            int cur_val = val + mid - 1;
            int prev_cost = (mid - 1)*i;
            int cur_x = x - prev_cost;

            if(cur_x >= cur_val){
                D = mid ;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return D;
    };

    sort(all(a));
    int ans = 0;
    int sm = 0;
    for(int i =0 ;i < n;i++){
        ans += days(a[i] , x - sm, i);
        sm += a[i]  ;
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