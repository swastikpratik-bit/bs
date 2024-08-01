#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define leadingzero __builtin_clzll
#define trailingzero __builtin_ctzll
#define bitsParity __builtin_parity
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define int long long
#define vll vector<int>
#define vbb vector<bool>
#define vss vector<string>
#define vpp vector<pair<int, int>>

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

const int MOD = 1000000007;


//------------------------------ SOLVE -------------------------------------
/*
        --> READ PROPERLY (READ AGAIN)
        --> THINK > FORMULATE > STRUCTURE CODE > CODE
        --> Check variables, overflows
        --> DEBUG
        --> SUBMIT
 
        * special cases (n=1?)
        * do something instead of nothing and stay organized
        * WRITE STUFF DOWN
        * DON'T GET STUCK ON ONE APPROACH
 
        * try to apply brute force first > 
        * think greedy > 
        * Don't Overthink about complexity >
        * Use pen-copy > 
*/

void super(int test, int totTest)
{
    int n, q;
    cin>>n>>q;

    string s , t;
    cin>>s>>t;

    vector<vector<int>> A(n , vector<int> (26));
    vector<vector<int>> B(n , vector<int> (26));

    for(int i = 0 ;i  < n;i++){
        if(i != 0 ){
            A[i] = A[i - 1];
            B[i] = B[i - 1];
        }
        A[i][s[i] - 'a']++;
        B[i][t[i] - 'a']++;
    }

    while(q--){
        int l , r ;
        cin>>l>>r;

        vector<int> S(26) , T(26)   ;

        for(int i = 0 ;i < 26 ;i++){
            S[i] = A[r - 1][i] ;
            if(l != 1)S[i] -= A[l - 2][i]   ; 
            T[i] = B[r - 1][i] ;
            if(l != 1)T[i] -= B[l - 2][i]   ; 
        }

        int oper = 0 ;
        for(int i =0 ;i <26 ;++i){
            oper += max(0ll , T[i] - S[i]);
        }
        cout<<oper<<endl;
    }
}

//------------------------- MAIN -------------------------------------
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