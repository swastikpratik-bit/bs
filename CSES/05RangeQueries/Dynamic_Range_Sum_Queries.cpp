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
    int sum;
    node(){
        sum = 0;
    }
};

class SGT{
    node * seg;

    public : 

    SGT(int n){
        seg = new node[4*n + 1];
    }

    node merge(node a , node b){
        node ans ;
        ans.sum = a.sum + b.sum;
        return  ans;
    }

    void build(int id , int l , int r , vector<int> &arr){
        if(l == r){
            seg[id].sum += arr[l];
            return;
        }

        int mid = (l + r)/2;
        build(2*id , l , mid , arr);
        build(2*id + 1, mid + 1, r , arr);

        seg[id] = merge(seg[2*id], seg[2*id + 1]);
    }
    
    void update(int id , int l ,int r , int pos , int val){
        if(pos > r || pos < l) return;

        if(l == r){
            seg[id].sum = val;
            return;
        }

        int mid = (l + r)/2;
        update(2*id , l, mid , pos, val);
        update(2*id + 1, mid + 1, r,pos , val);
        seg[id] = merge(seg[2*id], seg[2*id + 1]);

    }

    node query(int id, int l , int r , int left , int right){

        if(l > right || r < left)return node();

        if(l >= left && r <= right)return seg[id];

        int mid = (l + r)/2;

        node L = query(2*id , l , mid ,left , right);
        node R =query(2*id + 1, mid + 1, r , left , right);

        return merge(L , R) ;
    }
};


void super(int test, int totTest)
{
    int n, q;
    cin>>n>>q;

    vector<int> arr(n);
    for(auto &x : arr)cin>>x;

    SGT obj(n)  ;
    obj.build(1, 0 , n - 1, arr);

            // cout<<(obj.query(1, 0 , n - 1, 0, 3).sum)    <<endl;

    while(q--){
        int type ;
        cin>>type;

        if(type == 1){
            int p , v;
            cin>>p>>v;
            p--;
            obj.update(1, 0 , n -1 , p , v);
        }
        else{
            int a , b;
            cin>>a>>b;
            a-- , b--;

            cout<<(obj.query(1, 0 , n - 1, a, b).sum)    <<endl;
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