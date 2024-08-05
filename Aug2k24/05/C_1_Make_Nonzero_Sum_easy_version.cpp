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
    cin>>n ;

    vector<int> a(n);
    for(auto &x : a  ){
        cin>>x;
    }

    if(n&1){
        cout<<-1<<endl;
        return;
    }

    vector<vector<int>> ans;
    for(int i =1 ;i < n;i+=2){
        if(a[i] == a[i - 1]){
            ans.push_back({i , i + 1});
        }
        else{
            ans.push_back({i , i});
            ans.push_back({i  + 1 , i + 1});
           
        }
    }

    cout<<ans.size()<<endl;
    for(int i= 0 ;i < ans.size();i++){
        for(int j =0 ; j < 2 ;j++){
            cout<<ans[i][j] <<" ";
        }
        cout<<endl;
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