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
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;


    auto give = [](int a1 , int a2 , int b1 , int b2){
        int cnt = 0 ;
        if(a1 > a2)cnt++;
        else if( a1 < a2)cnt--;

        if(b1 > b2)cnt++;
        else if(b1 < b2)cnt--;
        return (cnt > 0);
    };

    cout<<((give(a1 , b1, a2 , b2) + give(a1 , b2 , a2 , b1) + give(a2 , b1 , a1 , b2) + give(a2 , b2 , a1 , b1)))<<endl;
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