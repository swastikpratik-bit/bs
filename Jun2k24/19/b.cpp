#include <bits/stdc++.h>
#define int long long
using namespace std;

void func(){
    int n, m;
    cin >> n >> m;


    if(m >= n){
        int extra = m % n;
        int canMake = n - extra;
        cout <<min(extra , canMake)<< endl;
    }
    else{
        cout << (n - m) << endl;
    }
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