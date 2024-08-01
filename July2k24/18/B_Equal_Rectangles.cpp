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
    int n;
    cin>>n;
    
    map<int , int> mp;
    for(int i = 0 ;i < 4*n ;i++){
        int x;
        cin>> x;
        mp[x]++;
    }

    vector<int> a;
    for(auto &[x , y] : mp){
        if(y&1){
            cout<<"NO"<<endl;
            return;
        }
        int times = y/2;
        y/=2;
        while(times--)a.push_back(x);
    }

    sort(all(a));
    int N = a.size();
    int area = a[0] * a[N -1];
    for(int i = 0  ;i < N ;i++){
        if(a[i]*a[N - i - 1] != area){
            cout<<"NO"<<endl;return;
        }
    }
    cy;


    // cout<<a.size()<<endl;
    // for(int i = 1 ;i < a.size();i++){
    //     int need = a[0]*a[i];
    //     map<int,int> mpp = mp;
    //     mpp[a[0]]--;
    //     mpp[a[i]]--;
    //     int f = 1;
    //     for(auto &[x, y] : mpp){

    //         if(y == 0)continue;

    //         if(need%x != 0){
    //             f = 0;
    //             break;
    //         }

    //         int req = need/x;
    //         if(mpp[req] < y){
    //             f = 0;
    //             break;
    //         }

    //         mpp[req] -= y;
    //     }
    //     if(f){
    //         cout<<"YES"<<endl;
    //         return;
    //     }
        
    // }
    // cout<<"NO"<<endl;



    
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