#include <bits/stdc++.h>
#define int long long
using namespace std;


void func(){
    string s;
    cin >> s;

    int n = s.size();

    vector<pair<pair<int,int>,char>> vp(n);

    int score = 0;
    for (int i = 0; i < n; i++)
    {
        vp[i].first.first = score;
        vp[i].first.second = (- i - 1);
        vp[i].second = s[i];

        if(s[i] == '(')
            score++;
        else if(s[i]== ')')
            score--;
    }

    sort(vp.begin(), vp.end());

    for(auto x : vp){
        cout << x.second;
    }
    cout << endl;
}

int32_t main()
{

    // int t;
    // cin >> t;

    // while (t--)
    // {
        func();
    // }
    return 0;
}