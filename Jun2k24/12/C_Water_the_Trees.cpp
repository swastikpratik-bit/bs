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

bool helper(int mid, vector<int> &A , int target){
    int one = (mid + 1) / 2;
    int two = mid - one;

    int needOne = 0;

    for(auto &x : A){
        int cur = (target - x) / 2;
        if((target - x )%2 == 1){
            needOne++;
        }

        if(two >= cur){
            two -= cur;
        }
        else{
            cur -= two;
            two = 0;
            needOne += cur * 2;
        }
    }

    return needOne <= one;
}

int bs(int target , vector<int> &A){
    int low = 0, high = 1e18;
    int ans = 0;
    while (high >= low)
    {
        int mid = (high + low) >> 1;

        if(helper(mid , A , target)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
}

void super(int test, int totTest)
{
    int N;
    cin >> N;

    
    vector<int> A(N);
    int target = 0;
    for (int i = 0; i < N;i ++){
        cin >> A[i];
        target = max(target, A[i]);
    }

    cout <<min(bs(target , A) , bs(target + 1, A)) << endl;
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
