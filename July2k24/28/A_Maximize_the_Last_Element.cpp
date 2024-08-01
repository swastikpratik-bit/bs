#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n ;
    cin>>n;
    vector<int> a(n)    ;
    for(auto &x : a)cin>>x;

    int ans = 0;
    for(int i =0 ;i < n;i+=2){
        ans = max(ans, a[i]);
    }

    cout<<ans<<endl;
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
