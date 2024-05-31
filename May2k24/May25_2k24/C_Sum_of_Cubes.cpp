// Problem Link -> https://codeforces.com/contest/1490/problem/C

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

void super(int test)
{
    int x;
    cin >> x;

    int cur = 1;
    int cube = 1;
    vector<int> cubes;
    while (cube <= x)
    {
        cubes.push_back(cube);
        cur++;
        cube = (cur * cur * cur);
    }

    for (int i = 0; i < cubes.size(); i++){
        int a = cubes[i];
        int b = x - a;

        int it = lower_bound(cubes.begin(), cubes.end(), b) - cubes.begin();

        if(cubes[it] == b){
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

    int test = 1;
    while (testcases--)
    {
        super(test++);
    }

    return 0;
}
