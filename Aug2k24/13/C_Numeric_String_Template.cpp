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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    while(m-->0){
        string s;
        cin >> s;
        if (s.size() != n) {
            cout << "NO" << endl;
            continue;
        }

        unordered_map<int, char> mp1;
        unordered_map<char, int> mp2;
        
        for (int k = 0; k < n; k++) {
            if (mp1.find(a[k]) != mp1.end()  && mp1[a[k]] != s[k]) {
                cout << "NO" << endl;
                goto done;
            }
            if (mp2.find(s[k]) != mp2.end() && mp2[s[k]] != a[k]) {
                cout << "NO" << endl;
                goto done;
            }
            mp1[a[k]] = s[k];
            mp2[s[k]] = a[k];
        }
        cout << "YES" << endl;
        done:
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