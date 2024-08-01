#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n; 
    cin>>n;

    vector<int> a(n);
    for(auto &x : a)cin>>x;

    int ans = 0;
    if (is_sorted(a.begin(), a.end()))
        ans = 0;
    else if (a[0] == 1 || a[n - 1] == n)
        ans = 1;
    else if (a[0] == n && a[n - 1] == 1)
        ans = 3;
    else 
        ans = 2;

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
