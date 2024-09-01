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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> dp(n, vector<int>(m, 0));
  
    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j <= m - k; j++) {
            for (int x = i; x < i + k; x++) {
                for (int y = j; y < j + k; y++) {
                    dp[x][y]++;
                }
            }
        }
    }


    int w;
    cin>>w;

    vector<int> a(w) , v;
    for(auto &x : a)cin>>x;

    sort(all(a));


    for(int i =0 ;i < n;i++){
        for(int j=0; j <m ;j++){
            if(dp[i][j] ){
                v.push_back(dp[i][j]);
            }
        }
    }

    sort(all(v));
    int last = v.size() - 1;
    int ans =0 ;
    for(int i = w - 1; i >=0 ;i--){
        ans += (a[i]*v[last--]);
        
    }
    cout<<ans<<endl;


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