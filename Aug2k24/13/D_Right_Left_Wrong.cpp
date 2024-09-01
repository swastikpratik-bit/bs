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
//--------------------------------- DEBUGER ----------------------------------------

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

void super(int test, int totTest)
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> pref(n + 1);
    pref[1] = a[0] ;
    for(int i = 2 ;i <= n;i++){
        pref[i] = pref[i - 1] + a[i - 1];
    }

    string s;
    cin >> s;
    
    set<int> right ;
    vector<int> left;
    int lastRight = -1;
    int cnt = 0 ;
    for(int i=0 ;i < n;i++ ){
        if(s[i] == 'R'){
            right.insert(i);
            lastRight  = i ;
            cnt++;
        }
        else{
            if(i == 0){
                left.push_back(i);
               
            }
            else if(i > 0 && s[i - 1] != 'L'){
                left.push_back(i);
            }
        }
    }

    if(cnt == n){
        cout<<0<<endl;
        return;
    }


    int highest = pref[lastRight] - pref[left[0] - 1];
    int ans = 0 ;
    for(int i = left.size() - 1;i >= 1 ;i--){
        
        
        auto it = upper_bound(all(right) , left[i]);
        if(it != right.end()){
            int ind = *it;
            right.erase(it);
            ans += pref[ind + 1] - pref[left[i]];        
        }        
    }

    int ma = 0;
    for(auto &x : right){
        ma =max(ma ,pref[x + 1] -  pref[left[0]]);
    }
    
    cout<<max(ans + ma, highest)<<endl;
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