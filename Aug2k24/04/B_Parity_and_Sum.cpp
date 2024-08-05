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

    int longestEven = -1 ;
    int longestOdd = -1 ;
    int even = 0;
    vector<int> a(n)    ;
    for(int i = 0 ;i< n;i++){
        cin>>a[i];

        if(a[i]%2 == 0){
            even++;
            longestEven = max(longestEven , a[i]);
        }
        else{
            longestOdd = max(longestOdd , a[i]);
        }
    }

    if(even == 0 || even == n){
        cout<<0<<endl;
        return;
    }

    sort(all(a));
    int ans = 0 ;
    for(int i= 0 ;i <n ;i++){
        if(a[i] %2 == 0){
            if(a[i] < longestOdd)a[i] += longestOdd;
            else{

                ans++;
                longestOdd += longestEven ;
            }
            ans++;
            longestOdd = max(longestOdd , a[i]);
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