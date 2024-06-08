#include <bits/stdc++.h>
#define int long long
using namespace std;

void func(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vector<int> f(7);
    for (int i = 0; i < n;i++){
        f[s[i] - 'A']++;
    }

    int ans = 0;
    for (int i = 0; i < 7; i++)
    {
        ans += max(0ll,  m- f[i]);
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