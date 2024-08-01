#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    int cnt = 0;

    int cur = n + 1;
    while(k > 0){
        cnt++;
        k -= cur;
        cur--;
        // if(cur < 0)break;
    }


    cout<<cnt<<endl;

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
