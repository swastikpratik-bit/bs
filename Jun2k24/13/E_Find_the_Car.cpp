// Problem Link -> 

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
    int N, K, Q;
    cin >> N >> K >> Q;

    vector<int> A(K+ 1), B(K+ 1);
    A.push_back(0);
    B.push_back(0);

    for (int i = 1; i <= K;i++){
        cin >> A[i];
    }
    for (int i = 1; i <= K;i++){
        cin >> B[i];
    }
    vector<int> ans;
    for (int i = 0; i < Q; i++)
    {
        int D;
        cin >> D;

        int l = 0, r = K;
        while(l <= r)
        {
            int mid = l+r>>1;
            if(A[mid] > D)
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        int it = r;
        if(A[it] == D){
            ans.push_back(B[it]);
            cout << B[it] << " ";
        }
        else{
           
            cout << B[it] + (D - A[it])*(B[it + 1 ]- B[it])/(A[it + 1]-A[it]) << " ";
        }
    }
    cout << endl;
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
