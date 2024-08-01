#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){

    int n ;
    cin>> n;

    cout<<n/4 + (n%4 != 0)<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
