#include <bits/stdc++.h>
#define int long long
using namespace std;

void func(){
    int x;
    cin >> x;

    string s = to_string(x);
    for (int i = 0; i < s.size();i++){
        if(i == 0 && s[i] != '1'){
            cout << "NO" << endl;
            return;
        }

        if (i == s.size() - 1 && s[i] == '9'){
            cout << "NO" << endl;
            return;
        }
    }

    for (int i = 1; i < s.size() - 1;i++){
        if(s[i] == '0'){
             cout << "NO" << endl;
            return;
        } 
    }

        cout << "YES" << endl;
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