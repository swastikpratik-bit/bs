#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int n;
    cin>>n;

    vector<int> a(n);
    int ma = 0;
    int mi = 1e9;
    for(auto &x : a){
        cin>>x;
        mi = min(mi , x);
        ma= max(ma , x);
    }
    sort(a.begin() , a.end());
    string ans ="";
    for(int i = 1 ;i< n ;i++){
        if(a[i] != a[i - 1] + 1){
            int left = a[i - 1] + 1;
            int right = a[i] - 1;
            string here;
            if(left == right){
                here = to_string(left);
            }
            else{
                here = to_string((a[i - 1] + 1));
                here += "-";
                here += to_string((a[i] - 1));
            }
            here += ",";
            ans += here;

        }
    }

    ans.pop_back();
    cout<<ans<<endl;

    return 0;
}