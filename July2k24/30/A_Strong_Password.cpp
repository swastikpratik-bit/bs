#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    string s;
    cin>>s;

    // brute 

    int n = s.size();
    auto time = [](string t){
        int cr = 2;
        for(int i = 0 ;i < t.size() - 1;i++){
            if(t[i] == t[i + 1]){
                cr++;
            }
            else{
                cr += 2;
            }
        }
        return cr;
    };

    string ans = "";
    int mx = -1e9;
    for(int len = 0 ; len <= n ;len++){
        for( char ch = 'a' ; ch <= 'z'  ; ch++){
            string cur = s.substr(0 , len) + ch + s.substr(len);

            int here =time(cur);
            if(here > mx){
                mx = here;
                ans = cur;
            }
        }
    }

    cout<<ans<<endl;
   
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
