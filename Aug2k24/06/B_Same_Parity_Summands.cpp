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
    int n , k ;
    cin>>n>>k;

    // for even 
    int even = n - (k - 1)*2;

    if(even >= 2 &&  even % 2 == 0){
        cout<<"YES"<<endl;
        for(int i= 0;i < k -1;i++){
            cout<<2<<" ";
        }
        cout<<even<<endl;
        return ;
    }    

    int odd = n - (k - 1);
    if(odd >= 1 && odd%2 == 1){
        cout<<"YES"<<endl;
        for(int i= 0;i < k -1;i++){
            cout<<1<<" ";
        }
        cout<<odd<<endl;
        return ;
    }

    cout<<"NO"<<endl;




    
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