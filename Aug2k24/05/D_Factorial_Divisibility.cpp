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
    int n , x;
    cin>>n>>x;

    vector<int> cnt(x + 1); 
    for(int i=0 , x ;i < n;i++){
        cin>>x;
        cnt[x]++;
    }

    for(int i = 1;i < x ;i++){
        if(cnt[i]%(i + 1) == 0){
            cnt[i + 1] += (cnt[i]/(i + 1));
        }
        else{
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;







    
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcases = 1;
    // cin >> testcases;
    int totTest = testcases;

    int test = 1;
    while (testcases--)
    {
        super(test++, totTest);
    }

    return 0;
}