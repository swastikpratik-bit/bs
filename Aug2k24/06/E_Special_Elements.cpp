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

    vector<int> a(n);
    map<int,int>mp;
    
    for(int i = 0;i <n ;i++){
        cin>>a[i];
        mp[a[i]]++;
    }

    int ans = 0 ;
    for(int i =0 ;i < n;i +=1 ){
        int sum = 0 ;
        for(int j = i ; j <  n ;j++){
            sum += a[j];
            if(i == j)continue;
            ans += mp[sum];
            mp[sum] = 0 ;
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