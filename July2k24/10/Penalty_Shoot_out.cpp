#include <bits/stdc++.h>
#define int long long
using namespace std;

void func(){
    int x, y;
    cin >> x >> y;
    
    if(x == y){
        cout << "YES" << endl;
    }
    else if(x < y && x + 2 >= y){
        cout << "YES" << endl;
        
    }
    else if(x > y && y + 1 == x){
        cout << "YES" << endl;

    }
    else{
        cout << "NO" << endl;
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