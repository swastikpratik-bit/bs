#include <bits/stdc++.h>
#define int long long
using namespace std;

void func(){
    int n, m;
    cin >> n >> m;

    map<int, int> A, B;

    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        x %= m;
        A[x]++;
    }
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        x %= m;
        B[x]++;
    }

    int ans = 0;
    for (auto [x, y] : A)
    {
        if(x == 0){
            ans += B[0]*y;
        }
        else{
            ans += B[m - x] * y;
        }
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