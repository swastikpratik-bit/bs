#include <bits/stdc++.h>
#define int long long
using namespace std;

void func(){
    int  n;
    cin >> n;

    int x = 1;
    while(x*2 <= n){
        x <<= 1;
    }
    cout << (n - x) * 2 << endl;
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