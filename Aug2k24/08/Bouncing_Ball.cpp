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

    vector<int> a(n)    ;
    vector<int> pref(n) , suff(n)   ;

    for(auto &x : a)    cin>>x;

    pref[0] = a[0];

    for(int i = 1 ;i < n;i++){
        pref[i] = pref[i - 1] + a[i];
    }

    suff[n - 1] = a[n -1];
    for(int i = n -2 ;i>= 0 ;i--){
        suff[i] = suff[i + 1] + a[i];
    }


    int ans = 0 ;
    for(int i=0  ;i < n;i++){
        if(a[i] == 0){
            int left = pref[i];
            int right = suff[i];

            if(right == left)ans+= 2;
            else if(abs(right - left) == 1)ans++;
        }
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