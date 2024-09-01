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
    int l , r; 
    cin>>l>>r;
    
    if(l == r){
        cout<<1<<endl;
        return;
    }
    int ans = 1;
    int low = 0 ;
    int high  = 1e9;
    for(int i = 0 ;i < 100000;i++){
        int here = i*(i + 1)/2;
        if(here <= r - l){
            ans = max(ans , i);
        }
        else{
            break;
        }
    }

    cout<<ans + 1<<endl;
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