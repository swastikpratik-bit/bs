// Problem Link -> https://codeforces.com/problemset/problem/1882/B

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
    int n;
    cin >> n;

    set<int> tot;
    vector<vector<int>> Allsets;
    map<int, int> freq;
    map<int, vector<int>> ind;
    for (int i = 0; i < n; i++)
    {
        int sz;
        cin >> sz;
        vector<int> tt(sz);
        for (int j = 0; j < sz; j++){
            int x;
            cin >> x;

            tt.push_back(x);
            freq[x]++;
            tot.insert(x);
            ind[x].push_back(i);
        }
        Allsets.push_back(tt);
    }

    int ans = 0;

    for(auto &x : tot){
        set<int> t2 = tot;
        map<int, int> curfreq = freq;

        for (int i = 0; i < ind[x].size();i++){
            for (int j = 0; j < (int)Allsets[ind[x][i]].size();j++){
                curfreq[Allsets[ind[x][i]][j]]--;
                if(curfreq[Allsets[ind[x][i]][j]] == 0){
                    t2.erase(Allsets[ind[x][i]][j]);
                }
            }
        }
        ans = max(ans, (int)t2.size());
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
