#include <bits/stdc++.h>
#define int long long
using namespace std;

void func(){
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 1e9; i >= 10; i/= 10){
        while(n >= i){
            ans += i;
            int get = i / 10;
            n -= i;
            n += get;
        }
    }
    ans += n;
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