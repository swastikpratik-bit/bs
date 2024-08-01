#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m;
    cin>>n>>m;

    vector<int> a(n) , b(m) ;
    for(auto &x : a)cin>>x;
    for(auto &x : b)cin>>x;

    sort(a.begin(), a.end());

    for(int i =0 ;i <m ;i++){
        int it = upper_bound(a.begin(), a.end() , b[i]) - a.begin();

        cout<<it<<" ";
    }cout<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
