// Problem Link -> https://codeforces.com/problemset/problem/1913/C

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
    
}

//------------------------- MAIN -------------------------------------
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map < ll , ll > ma,val;
    ma[0] = 1ll;
    for(ll i = 1ll ; i < 30 ; i++) {
        ma[i] = ma[i-1ll]*2ll;
    }
 
    ll n,a,b;
    cin>>n;
    for(ll i = 0 ; i < n ; i++) {
        cin>>a>>b;
        if(a == 1) {
            val[ma[b]]++;
        }
        else {
 
            for(ll i = 30 ; i >= 0 ; i--) {
                if(b >= ma[i] and b!=0) {
                    if(val.count(ma[i])) {
                        b-=min(b/ma[i],val[ma[i]])*ma[i];
                    }
                }
            }
            if(b == 0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;

        }
    }

    return 0;
}
