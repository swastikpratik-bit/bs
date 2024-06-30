#include <bits/stdc++.h>
#define int long long
using namespace std;

void func(){
    int n, k;
    cin >> n >> k;

    int ans = (n - 1) * k + 1;
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