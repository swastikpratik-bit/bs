// // Problem Link -> 

// #include <bits/stdc++.h>

// using namespace std;

// #define pb push_back
// #define ppb pop_back
// #define ff first
// #define ss second
// #define PI 3.141592653589793238462
// #define set_bits __builtin_popcountll
// #define leadingzero __builtin_clzll
// #define trailingzero __builtin_ctzll
// #define bitsParity __builtin_parity
// #define all(x) (x).begin(), (x).end()
// #define rall(x) (x).rbegin(), (x).rend()
// #define cy cout << "YES" << endl
// #define cn cout << "NO" << endl
// #define int long long
// #define vll vector<int>
// #define vbb vector<bool>
// #define vss vector<string>
// #define vpp vector<pair<int, int>>

// typedef long long ll;
// typedef unsigned long long ull;
// typedef long double lld;

// const int MOD = 1000000007;


// //------------------------------ SOLVE -------------------------------------
// /*
//         --> READ PROPERLY (READ AGAIN)
//         --> THINK > FORMULATE > STRUCTURE CODE > CODE
//         --> Check variables, overflows
//         --> DEBUG
//         --> SUBMIT
 
//         * special cases (n=1?)
//         * do something instead of nothing and stay organized
//         * WRITE STUFF DOWN
//         * DON'T GET STUCK ON ONE APPROACH
 
//         * try to apply brute force first > 
//         * think greedy > 
//         * Don't Overthink about complexity >
//         * Use pen-copy > 
// */

// void super(int test, int totTest)
// {
//     int n;
//     cin >> n;

//     int sA = 0, sB = 0;
//     vector<int> a(n), b(n);
//     for(auto &x : a){
//         cin >> x;
//         sA += x;
//     }
//     for(auto &x : b){
//         cin >> x;
//         sB += x;
//     }

//     int curA = 0, curB = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if(curA == curB){

//         }
//     }
// }

// //------------------------- MAIN -------------------------------------
// int32_t main()
// {

//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int testcases = 1;
//     cin >> testcases;
//     int totTest = testcases;

//     int test = 1;
//     while (testcases--)
//     {
//         super(test++, totTest);
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        for (int j = 0; j < n; j++) {
            cin >> b[j];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int pos_a = 0, pos_b = 0;
        int rating_a = 0, rating_b = 0;

        while (pos_a < n && pos_b < n) {
            if (a[pos_a] > b[pos_b]) {
                rating_a += a[pos_a];
                pos_a++;
            } else {
                rating_b += b[pos_b];
                pos_b++;
            }
        }

        while (pos_a < n) {
            rating_a += a[pos_a];
            pos_a++;
        }

        while (pos_b < n) {
            rating_b += b[pos_b];
            pos_b++;
        }

        cout << max(min(rating_a, rating_b), 0) << endl;
    }

    return 0;
}
