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


void super(int test, int totTest)
{
    ll n;
    cin >> n;
    vector<ll> v(n),p(n+1,-1),q(n+1,-1);
    vector<ll> ans_p(n,0), ans_q(n,0);
    set<ll> set_p,set_q;
 
    for(ll i=0 ; i<n ; ++i){
        cin >> v[i];
        set_p.insert(i+1);
        set_q.insert(i+1);
    }
    
    for(ll i=0 ; i<n ; ++i){
        if(p[v[i]] == -1){
            p[v[i]] = i;
            ans_p[i] = v[i]; 
            set_p.erase(v[i]);
        }
        else if(q[v[i]] == -1){
            q[v[i]] = i;
            ans_q[i] = v[i];
            set_q.erase(v[i]);
        }
        else{
           cout<<"NO"<<endl;
           return;
        }
    }
    
    for(ll i=0 ; i<n ; ++i){
        if(p[v[i]] == i){
            auto itr = set_q.upper_bound(v[i]);
 
            if(itr == set_q.begin())
                {
                cout<<"NO"<<endl;
                return;
            }
 
            itr = prev(itr);
            ans_q[i] = *itr;
            set_q.erase(ans_q[i]);
        }
        else if(q[v[i]] == i){
            auto itr = set_p.upper_bound(v[i]);
 
            if(itr == set_p.begin())
            {
                cout<<"NO"<<endl;
                return;
            }
 
            itr = prev(itr);
            ans_p[i] = *itr;
            set_p.erase(ans_p[i]);
        }
    }
 
    cout << "YES" << endl;
    for(ll i=0 ; i<n ; ++i)
        cout << ans_p[i] << " ";
    cout << endl;
 
    for(ll i=0 ; i<n ; ++i)
        cout << ans_q[i] << " ";
    cout << endl;

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