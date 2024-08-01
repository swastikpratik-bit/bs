#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n , m;
    cin>>n>>m;
    
    map<int,int> mp;
    for(int i =0 ;i < n;i++){
        int x; 
        cin>>x;

        mp[x]++;
    }

    vector<pair<int,int>> vals;
    for(auto &[x , y] :mp){
        vals.push_back({x , y});
    }

    for(int i = 1 ;i < vals.size(); i++){
        // if(vals[i].first)
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
