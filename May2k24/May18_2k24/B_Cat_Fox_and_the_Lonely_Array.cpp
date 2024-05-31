// Problem Link -> https://codeforces.com/contest/1973/problem/B

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

bool helper(int k ,int n , vector<int> &a ) {
    vector<int> bits(21);
    for (int i = 0; i < k;i++){
        for (int bit = 0; bit < 21;bit++){
            if(a[i]&(1<<bit)){
                bits[bit]++;
            }
        }
    }

    int first_window = 0;
    for (int bit = 0; bit < 21;bit++){
        if(bits[bit]){
            first_window += (1 << bit);
        }
    }

    for (int i = k; i < n;i++){
        for (int bit = 0; bit < 21;bit++){
            if(a[i]&(1<<bit)){
                bits[bit]++;
            }
        }

        for (int bit = 0; bit < 21;bit++){
            if(a[i- k]&(1<<bit)){
                bits[bit]--;
            }
        }

        int cur_window = 0;
        for (int bit = 0; bit < 21;bit++){
            if(bits[bit]){
                cur_window += (1 << bit);
            }
        }

        if(first_window != cur_window){
            return false;
        }
    }

    return true;
}

void super(int test)
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a)
        cin >> x;

    int low = 1, high = n;
    int ans = n;

    while(high >= low){
        int mid = (high + low) / 2;

        if(helper(mid , n, a)){
            high = mid - 1;
            ans = mid;
        }
        else{
            low = mid + 1;
        }
    }
    cout << ans << endl;
}

//------------------------- MAIN -------------------------------------
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcases = 1;
    cin >> testcases;

    int test = 1;
    while (testcases--)
    {
        super(test++);
    }

    return 0;
}
