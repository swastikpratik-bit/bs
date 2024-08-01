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


void super(int test, int totTest)
{
    int n;
    cin>>n;

    int st = 1;
    int last = n*n;

    int f = 1 ;
    vector<vector<int>> ans(n, vector<int> (n));
    for(int i =0 ;i < n;i++){
        for(int j =0 ;j < n;j++){
            if(f)ans[i][j] = last--;
            else ans[i][j] = st++;
            f ^= 1;
        }
        if(i&1){
            reverse(ans[i].begin() , ans[i].end());
        }
    }

    for(int i=0 ;i < n;i++){
        for(int j =0 ; j< n;j++){
            cout<<ans[i][j]<<" \n"[j == n-1];
        }
    }

    
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