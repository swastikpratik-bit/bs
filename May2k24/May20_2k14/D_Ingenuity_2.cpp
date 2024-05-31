// Problem Link -> https://codeforces.com/contest/1974/problem/D

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
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<vector<int>> dir(4);
    // E, W, N, S;
    for (int i = 0;i < n;i++){
        if(s[i]== 'E')
            dir[0].push_back(i);
        else if(s[i]== 'W')
            dir[1].push_back(i);
        else if(s[i]== 'S')
            dir[2].push_back(i);
        else
            dir[3].push_back(i);
    }
    string ans(n , '#');

    int f = 1;
    for (int i = 0; i < 4;i+= 2){
        while (dir[i].size() > 0 && dir[i+ 1].size() > 0)
        {
            ans[dir[i].back()] = f? 'R': 'H';
            ans[dir[i+ 1].back()] = f? 'R': 'H';
            dir[i].pop_back();
            dir[i+ 1].pop_back();
            f ^= 1;
        }
    }

    for (int i = 2; i < 4;i++){
        for (int j = 0; j < 2;j++){ 
            while (dir[i].size() > 1 && dir[j].size() > 1)
            {
                ans[dir[i].back()] = f ? 'R' : 'H';
                ans[dir[j].back()] = f ? 'R' : 'H';
                dir[i].pop_back();
                dir[j].pop_back();
                f ^= 1;
                ans[dir[i].back()] = f ? 'R' : 'H';
                ans[dir[j].back()] = f ? 'R' : 'H';
                dir[i].pop_back();
                dir[j].pop_back();
                f ^= 1;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        while (dir[i].size() > 1)
        {
            ans[dir[i].back()] = f ? 'R' : 'H';
            dir[i].pop_back();
            ans[dir[i].back()] = f ? 'H' : 'R';
            dir[i].pop_back();
        }
    }

    if (dir[0].size() || dir[1].size() || dir[2].size() || dir[3].size())
    {
        cout << "NO" << endl;
        return;
    }

    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
    {
        if(ans[i] == 'R')
            c1++;
        else
            c2++;
    }
    if(c1 == 0 || c2 == 0){
        cout << "NO" << endl;
        return;
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
