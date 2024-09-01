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
    int  n , x , k ;
    cin>>n>>x>>k;

    vector<int> h(n);
    for(auto &x : h)cin>>x;

    sort(rall(h));

    int cnt = 0;

    int cur = x;
    int used = 0;
    if(h[0] > cur){
        cur *= k;
        used = 1;
    }
    for(int i = 0 ;i < n;i++){

        if(h[i] < cur){
            cnt++;
            cur = h[i];
        }
        else if(h[i] >= cur && used == 0){
            cur *= k;
            used = 1;
            if(h[i] < cur){
                cur = h[i];
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;



    

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