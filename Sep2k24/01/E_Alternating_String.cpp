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

    string s; 
    cin>>s;

    if(n == 1){
        cout<<1<<endl;
        return;
    }
    
    if(n&1){
    
        map<char, int> evenPos , oddPos , evLater , odLater;
        for (int i = 0; i < n - 1; i++) {
            if (i % 2 == 0) {
                evenPos[s[i]]++;
            } else {
                oddPos[s[i]]++;
            }
        }
        int oper = 0 ;
        int ma = 0 ;      
        for (auto&[x , y] : evenPos) {
            ma = max(ma, y);
        }
        oper += n/2 - ma;
        ma = 0;

        for (auto&[x , y] : oddPos) {
            ma = max(ma, y);
        }
        oper += n/2 - ma;
        int ans = 1e9;
        ans = min(ans,oper);

        for (int i = n - 2; i >= 0; i--) {
            if (i % 2 == 0) {
                evenPos[s[i]]--;
                evLater[s[i + 1]]++;
            } else {
                oddPos[s[i]]--;
                odLater[s[i + 1]]++;
            }

            map<char, int> evCombined ,  odCombined;
            evCombined = evenPos ;
            odCombined = oddPos;

            for (auto&[x , y] : evLater) {
                evCombined[x] += y;
            }

            for (auto&[x, y] : odLater) {
                odCombined[x] += y;
            }

            int oper = 0 ;
            int ma = 0 ;      
            for (auto&[x , y] : evCombined) {
                ma = max(ma, y);
            }
            oper += n/2 - ma;
            ma = 0;

            for (auto&[x , y] : odCombined) {
                ma = max(ma, y);
            }
            oper += n/2 - ma;
            ans = min(ans,oper);
        }
        cout << ans + 1 << endl;       

    }
    else{

        map<char , int> evenPos , oddPos;
        for(int i = 0 ;i < n;i++){
            if(i%2 == 0)evenPos[s[i]]++;
            else oddPos[s[i]]++;
        }

        int oper = n;
        int ma  = 0 ;
        for( auto &[x , y] : evenPos){
            ma = max(ma , y);
        }
        oper  -=  ma;
        ma = 0;
        for( auto &[x , y] : oddPos){
            ma = max(ma , y);
        }

        oper -= ma;

        cout<<oper<<endl;
    }
       
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