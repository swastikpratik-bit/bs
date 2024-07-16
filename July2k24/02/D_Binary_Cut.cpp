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

void super(int test, int totTest)
{
    string s;
    cin >> s;

    if(is_sorted(all(s))){
        cout << 1 << endl;
        return;
    }

    // 111 , 00...111 , last 0...
    int n = s.size();
    int last = n - 1;
    int st = 0;
    // while (s[last] == '0')
    //     last--;

    // while(s[st] == '1')
    //     st++;
    int ans = 0;
    // if(last != n - 1)
    //     ans++;
    
    // if(st != 0)
    //     ans++;

    int f = 1;
    for (int i = st; i <= last; )
    {
        if (s[i] == '1' && s[i - 1] == '0' && f){
            while(s[i] == '1')
                i++;
            ans++;
            f = 0;
        }
        else if(s[i]== '1'){
            while(s[i] == '1')
                i++;
            ans += 2;
        }
        else{
            i++;
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
    int totTest = testcases;

    int test = 1;
    while (testcases--)
    {
        super(test++, totTest);
    }

    return 0;
}
