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

int minSwaps(vector<int>& nums) {

    int n = nums.size();
    
    int one = 0;
    for(int i = 0 ;i < n;i++){
        one += (nums[i] == 1);
    }

    int cur =  0; 
    for(int i= 0 ;i< one ;i++){
        cur += (nums[i] == 0);
    }

    int MinZero = cur;
    for(int i = one ;i < n + one ;i++){
        if(nums[i%n] == 0)cur++;
        if(nums[(i -one)%n] == 0)cur--;
        MinZero = min(MinZero , cur);
    }
    return MinZero;
    

}

void super(int test, int totTest)
{
    int n;
    cin>>n;

    vector<int> a(n)    ;
    for(auto &x : a)cin>>x;

    cout<<minSwaps(a)<<endl;
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