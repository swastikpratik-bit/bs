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

//--------------------------------- DEBUGER ----------------------------------------

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

 vector<vector<int>> grid;
int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(n < 3 || m < 3)return 0;

        auto sum = [&](int i , int j){
            int sum = grid[i][j] + grid[i][j + 1] + grid[i][i + 2];
            //l -> r
            vector<int> cnt(10);
            for(int a = i ;  a < i + 2 ; a++){
                for(int b = j ; b <j + 2 ;b++){
                    if(grid[a][b] > 9)return 0;
                    cnt[grid[a][b]] = 1;
                }
            }

            for(int a  = 1 ;a < 10;a++){
                if(cnt[a] == 0)return 0;
            }

            for(int a = i ;  a < i + 3 ;a++){
                if(grid[a][j] + grid[a][j + 1] + grid[a][j + 2] != sum)return 0;
            } 

            // u -> d
            for(int b = j ; b < j + 3 ;b++){
                if(grid[i][b] + grid[i + 1][b] + grid[i + 2][b] != sum)return 0;
            }

            // dig 
            if(grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] != sum)return 0 ;
            if(grid[i][j + 2] + grid[i + 1][j+ 1] + grid[i + 2][j] != sum)return 0 ;
            return 1;

        };

        int ans = 0;
        for(int i =0 ;i < n - 2 ;i ++){
            for(int j = 0 ; j < m - 2 ; j++){
                ans += sum(i , j);                
            }
        }  

        return ans;
    }

void super(int test, int totTest)
{
    grid = {{4, 3 , 8 ,4} , {9, 5, 1, 9} , {2, 7 , 6, 2}};

    cout<<numMagicSquaresInside(grid)<<endl;
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