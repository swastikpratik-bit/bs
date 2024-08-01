#include <bits/stdc++.h>
#define int long long
using namespace std;

// const int N = 200000 + 10;
// vector<int> ans;
void solve(){
    int n;
    cin>>n;

    if(n == 1){
        cout<<1<<endl<<1<<endl;
        return;
    }
    

    int bit = 0;

    int cur = 1;
    int cnt = 0;

    int i = 0;
    vector<int> ans(n );
    while(i < n){

        cnt = 0;
        while(cnt < (1ll<<bit) && i < n){
            ans[i] = cur;
            i++;
            cnt++;
        }
        cur++;
        bit++;
    }

    cout<<ans[n - 1]<<endl;
    for(int i= 0 ;i<  n ;i++){
        cout<<ans[i]<<" \n"[i == n- 1];
    }
    
    
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;


    // int bit = 0;

    // int cur = 1;
    // int cnt = 0;

    // int i = 0;
    // // vector<int> ans(n + 3);
    // while(i < 200005){

    //     cnt = 0;
    //     while(cnt < (1ll<<bit)){
    //         ans[i] = cur;
    //         i++;
    //         cnt++;
    //     }
    //     cur++;
    //     bit++;
    // }

    while (t--)
    {
        solve();
    }
    return 0;
}
