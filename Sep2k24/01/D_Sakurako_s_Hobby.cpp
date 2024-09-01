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
    cin >> n;

    vector<int> a(n);
    for(auto &x : a){
        cin>>x;
        x--;
    }

    string s;
    cin >> s;

    vector<int> ans(n, -1) , seen(n , 0);
    

    for (int i = 0; i < n; i++) {
        if (!seen[i]){   
            int val = 0;
            int j = i;
            while (!seen[j]) {
                seen[j] = 1;
                if (s[j] == '0') val++;
                j = a[j];
            }

            j = i;
            while (1) {
                ans[j] = val;
                j = a[j];
                if (j == i) break;
            }
        }
        
    }

    for(auto &x : ans)cout<<x<<" ";
    cout << endl;
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