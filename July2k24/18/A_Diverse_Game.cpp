#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m;
    cin>>n>>m;


    vector<vector<int>> a(n , vector<int> (m));
    vector<vector<int>> b(n , vector<int> (m));

    for(int i=0 ;i < n;i++){
        for(int j =0 ;j < m ;j++){
            cin>>a[i][j];
        }
    }

    for(int i=0 ;i < n;i++){
        for(int j =0 ;j < m ;j++){
            if(a[i][j] != n*m)b[i][j] = a[i][j] + 1;
            else{
                b[i][j] = 1;
            }
        }
    }

    if(a == b){
       cout<<-1<<endl;
    }
    else{
       for(int i=0 ;i < n;i++){
        for(int j =0 ;j < m ;j++){
            cout<<b[i][j]<<" ";
        }cout<<endl;
    }
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
