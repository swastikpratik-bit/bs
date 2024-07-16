#include <bits/stdc++.h>
#define int long long
using namespace std;

void func(){
    string s;
    cin >> s;

    int n = s.size();
    // cout << s << endl;
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if(s[i] == '0')
            cnt++;
        else
            break;
    }
    cout << cnt << endl;
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