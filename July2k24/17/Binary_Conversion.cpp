#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n , k;
    cin>>n>>k;

    string s, t;
    cin>>s>>t;


    int c1 = 0, c2 = 0;
    for(int i =0 ;i < n;i++){

        if(s[i] == '1')c1++;
        if(t[i] == '1')c2++;
    }

    if(c1 != c2){
        cout<<"NO"<<endl;
        return;
    }

    if(s == t){
        if(c1 >= 2 || (n - c1) >= 2){
            cout<<"YES"<<endl;
        }
        else if(k%2==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        return;

    }

    int notEq = 0;
    for(int i=0 ;i < n;i++){

        if(s[i] != t[i]){
            notEq++;
        }
    }

    int oper = notEq/2;
    int equal = n - notEq;


    if(oper == k && n == 2){
        cout<<"YES"<<endl;
    }
    else if(oper <= k && n > 2){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
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
