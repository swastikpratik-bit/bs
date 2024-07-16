#include <bits/stdc++.h>
#define int long long
using namespace std;

void func(){
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> mp;
    for (auto &x : a){
        cin >> x;
        mp[x]++;
    }

    int  ans = n - mp[1];
    for (auto &x : mp){
        ans = min((n - x.second) * x.first, ans);
    }

    for (int i = 0; i < n;i++){

    }
        cout << ans << endl;
}

int32_t main()
{

    int t;
    cin >> t;

    while (t--)
    {
        func();
    }
    return 0;
}