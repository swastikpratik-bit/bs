#include <bits/stdc++.h>
#define int long long
using namespace std;
int freq[26] , cnt;
bool mark[26];
void solve(){
    string s;
    cin>>s;


    for(int i =0 ;i < s.size();i++){
        freq[s[i] - 'a']++;
    }

    for(int i = 0 ;i< 26;i++){
        if(freq[i]&1){
            cnt++;
            freq[i]--;
            mark[i] = 1;
        }
    }

    for(int i = 0;i < 26;i++){
        if(mark[i]){
            freq[i] += min(cnt, 2ll);
            cnt -= min(cnt , 2ll);
        }
        if(!cnt)break;
    }

    for (int i = 0 ; i < 26 ; i ++){
        for (int j = 0 ; j < freq[i] / 2; j ++) cout << char(i + 'a');
    }
    for (int i = 0 ; i < 26 ; i ++) if (freq[i] & 1)    cout << char(i + 'a');
    for (int i = 26 ; ~i ; i --){
        for (int j = 0 ; j < freq[i] / 2 ; j ++) cout << char(i + 'a');
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
