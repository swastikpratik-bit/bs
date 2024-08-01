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
    cin>>n;

    int cnt = 0;
    set<int> st;
    for(int i=0 ;i <n ;i++){
        int x;
        cin>>x;
        st.insert(x);
        if(x == 0)cnt++;
    }
    
    if(st.size() == 2 && cnt > 0){
        cout<<"YES"<<endl;
        return;
    }
    cout<<(cnt == n - 1 || st.size() == 1 ? "YES": "NO")<<endl;

    



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