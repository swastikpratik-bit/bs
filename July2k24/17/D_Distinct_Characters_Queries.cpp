#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define leadingzero __builtin_clzll
#define trailingzero __builtin_ctzll
#define bitsParity __builtin_parity
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define int long long
#define vll vector<int>
#define vbb vector<bool>
#define vss vector<string>
#define vpp vector<pair<int, int>>

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

const int MOD = 1000000007;


//------------------------------ SOLVE -------------------------------------
/*
        --> READ PROPERLY (READ AGAIN)
        --> THINK > FORMULATE > STRUCTURE CODE > CODE
        --> Check variables, overflows
        --> DEBUG
        --> SUBMIT
 
        * special cases (n=1?)
        * do something instead of nothing and stay organized
        * WRITE STUFF DOWN
        * DON'T GET STUCK ON ONE APPROACH
 
        * try to apply brute force first > 
        * think greedy > 
        * Don't Overthink about complexity >
        * Use pen-copy > 
*/

struct node{
    int dist ;
    int bit ;
    node(){
        dist = 0;
    }
};

class SGT{
    
    node * seg;

    public:
    SGT(int n){
        seg = new node[4*n + 1]; 

    }
    node merge(node a , node b) {
        node ans;
        ans.dist = (a.dist | b.dist);
        return ans;
    }


    void build(int id , int l , int r , string &s){
        if(l == r){
            seg[id].dist = (1ll << (s[l] - 'a'));
            return ;
        }

        int mid = (l + r)/2;
        build(2*id , l , mid, s);
        build(2*id + 1, mid + 1, r, s);
        seg[id] = merge(seg[2*id] , seg[2*id + 1]);
    }

    void update(int id , int l , int r , int pos , char val){
        if(pos > r || pos < l)return ;

        if(l == r){
            seg[id].dist = (1ll<<(val - 'a'));
            return;
        }

        int mid = (l + r)/2;
        update(2*id , l, mid , pos, val);
        update(2*id + 1, mid + 1, r,pos , val);
        seg[id] = merge(seg[2*id], seg[2*id + 1]);
    }

    node query(int id , int l , int r , int left , int right){
        if(left > r || right < l)return node();

        if(l >= left && r <= right)return seg[id];

        int mid = (l + r)/2;
        
        node L = query(2*id , l , mid , left , right);
        node R = query(2*id + 1, mid + 1, r , left , right);

        return merge(L,R);
    }

};


void super(int test, int totTest)
{
    string s;
    cin>>s;
    int n = s.size();
    SGT obj(n);
    obj.build(1, 0 , n - 1, s);

    int q;
    cin>>q;

    while(q--){
        int type  ;
        cin>>type ;

        if(type ==1){
            int pos;
            char ch ;
            cin>>pos>>ch;
            obj.update(1, 0 ,n - 1, pos - 1, ch)    ;
        }
        else{
            int l , r ;
            cin>>l>>r;
            l--, r--;

            cout<<set_bits(obj.query(1, 0 , n -1 , l , r).dist)<<endl;
        }
    }
    





}

//------------------------- MAIN -------------------------------------
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcases = 1;
    // cin >> testcases;
    int totTest = testcases;

    int test = 1;
    while (testcases--)
    {
        super(test++, totTest);
    }

    return 0;
}