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

void bfs(int st , vector<int> &a , vector<int> &dis){
    queue<int> q;
    q.push(st)  ;
    dis[st] = 0;
    int n = a.size();
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int  j = 1 ; j <= a[cur] ;j++){
            int nxt = cur + j ;
            if(nxt <= n && dis[nxt] == -1){
                dis[nxt] = dis[cur] + 1;
                q.push(nxt);
            }
        }
    }
}

void super(int test, int totTest)
{
    int n, q;
    cin>>n>>q;

    vector<int> a(n + 1);
    for(int i = 1 ; i <= n;i++){
        cin>>a[i];
    }    

    while(q--){
        int s , e;
        cin>>s>>e;

        vector<int> dis(n + 1, -1);
        bfs(s , a , dis);
        cout<<dis[e]<<endl;
        
    }
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