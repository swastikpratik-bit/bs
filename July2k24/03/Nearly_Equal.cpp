#include <bits/stdc++.h>
#define int long long
using namespace std;

void func(){
    int n, m;
    cin >> n >> m;

    string a, b;
    cin >> a >> b;

    int ans = m;
    for (int i = 0; i <= n - m; i++)
    {
        int cnt = m;
        int k = i;
        for (int j = 0; j < m; j++)
        {
            if(a[k++] == b[j])
                cnt--;
        }
        // cout << cnt << endl;
        ans = min(ans, cnt);
    }
    cout << ans <<endl;
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