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
    string num;
    cin >> num;
    if(num.size() < 3){
        cout<<"NO"<<endl;
        return;
    }

    int x = stoi(num.substr(2));
    if (num[0] == '1' && num[1] == '0') {

        if(x >= 2 && num[2] != '0')
            cout << "YES" << endl;
             
        else cout << "NO" << endl;
        
    } else {
        cout << "NO" << endl;
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