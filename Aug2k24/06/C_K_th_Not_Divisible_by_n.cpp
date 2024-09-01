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
    int n, k;
    cin>>n>>k;

    int low = 0 , high  = k<<1;
    while(high >= low){
        int mid = ( low + high )/2;

        int tillNow = mid - (mid/n);
        if(tillNow > k){
            high = mid - 1;
        }
        else if(tillNow < k){
            low = mid + 1;
        }
        else{
            if(mid%n == 0)mid--;
            cout<<mid<<endl;
            return;
        }
    }

    cout<<low<<endl;

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