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
    int n, x;
    cin>>n>>x;

    vector<int> a(n + 1), dp(n + 2) , pre(n + 1);

   for(int i = 1;i <= n;i++){
    cin>>a[i]   ;
   }
    
    for(int i = 1;i <= n;i++){
        pre[i] = pre[i - 1] + a[i];
    }



    auto helper = [&](int low , int high , int i ){
        int ans = -1;
        while(high >= low){
            int mid = (low + high) >> 1;

            if(pre[mid] - pre[i - 1] > x){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        // if(ans == -1)return -1ll;
        // ans;
        return ans;
    };

    for(int i = n;i >= 0 ;i--){

        int p = helper(i , n , i) ;
        if( p != -1){
           dp[i] = dp[p + 1] + 1;
        }
    }

    int ans = n*(n + 1)/2;

    for(auto &x : dp){
        ans -= x;
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