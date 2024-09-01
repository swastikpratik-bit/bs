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
    int n , x , y ;
    cin>>n>>x>>y;

    string s; 
    cin>>s;
    // alice
    int X = 0 , Y = 0 ;
    for(int i = 0 ;i < n;i++){
        if(s[i] == 'R'){
            X++;
        }
        else if(s[i] == 'L'){
            X--;
        }
        else if(s[i] == 'U'){
            Y++;
        }
        else{
            Y--;
        }

        int dist = abs(x - X) + abs(y - Y);
        // debug(dist);
        if(dist <= i + 1  && dist%2 == (i + 1)%2){
            cout<<"Yes"<<endl;
            return;
        }
    }   
    cout<<"No"<<endl;
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