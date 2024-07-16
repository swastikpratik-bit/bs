#include <bits/stdc++.h>
#define int long long
using namespace std;

void func(){
    int n, k;
    cin >> n >> k;

    int equal = n - n % k;
    int total = equal + min(n % k, k / 2);
    cout << total << endl;
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