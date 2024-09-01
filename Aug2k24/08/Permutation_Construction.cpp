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

    vector<int>a(n);
    int st = 1 ;
    for(int i = 0 ;i < n;i+= 2){
        a[i] = st++;
    }

    int last = n;
    for(int i = 0;i < n;i++){
        if(a[i] == 0)a[i] = last--;
    }

    for(auto &x : a)cout<<x<<' ';
    cout<<endl;
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