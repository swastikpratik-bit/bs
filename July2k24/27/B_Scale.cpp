#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){

    int n, k;
    cin>>n>>k;

    char a[n][n];
    for(int i =0 ;i < n;i++){
        for(int j =0 ;j < n;j++){
            cin>>a[i][j];
        }
    }

    for(int i = 0 ; i < n ;i += k){
        for(int j = 0 ;j < n ;j+= k){
            cout<<a[i][j];
        }
        cout<<endl;
 
    }




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
