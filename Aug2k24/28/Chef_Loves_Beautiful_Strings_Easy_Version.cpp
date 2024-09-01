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
    cin>> n;

    string s; 
    cin>>s;

    int seg = 0;

    char last = s[0];
    seg = 1;
    for(int i = 1 ;i < n ;i++){
        if(s[i] != last){
            seg++;
            last = s[i];
        }
    }

    int rep = n - seg ;
    int initialScore = seg - 1;

    int ans = rep*initialScore;
    initialScore--;
    ans += (initialScore + 1)*initialScore/2;


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