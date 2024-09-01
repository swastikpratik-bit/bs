#include <bits/stdc++.h>

using namespace std;

#define set_bits __builtin_popcountll
#define leadingzero __builtin_clzll
#define trailingzero __builtin_ctzll
#define bitsParity __builtin_parity
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

const int MOD = 1000000007;

bool issubsequence(string& s1, string& s2)
{
    int n = s1.length(), m = s2.length();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s1[i] == s2[j])
            i++;
        j++;
    }
    return i == n;
}

void super(int test, int totTest)
{
    string s , t;
    cin>>s>>t;

    int n = s.size();
    int m = t.size();
    int i = 0 ;
    int j = 0 ;


    while(i < n && j < m){

        if(s[i] == t[j]){
            i++;
            j++;
            continue;
        } 
        if(s[i] != t[j] && s[i] == '?' ){
            s[i] = t[j] ;
            i++;
            j++;
        }

        if(s[i] != t[j] && s[i] != '?'){
            i++;
        } 
    }

    // cout<<s<<endl;

    if(j < m - 1){
        cout<<"NO"<<endl;
        return;
    }

    if(!issubsequence(t , s)){
        cout<<"NO"<<endl;
        return;
    }
    for(int i = 0 ;i < n;i ++){
        if(s[i] == '?'){
            s[i] = 'a'  ;
        }
    }

    cout<<"YES"<<endl;
    cout<<s<<endl;

}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcases = 1;
    cin >> testcases;
    int totTest = testcases;

    int test = 1;
    while (testcases--)
    {
        super(test++, totTest);
    }

    return 0;
}