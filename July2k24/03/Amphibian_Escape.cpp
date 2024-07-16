#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k, h;
void go(int &b , int &a){
while ((a * k - b * (k - 1)) >= h) {
                b++;
            }
}

void func(){
    cin >> n >> k >> h;

    if(n == 1){
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    int B = 1;
    for (int A = 1; A <= n;)
    {
        if(A >= h){
            ans += n;
            A++;
        }
        else{
            if((A * k) - (B*( k -1)) >= h){
                while((A*k) - (B*(k - 1)) >= h)B++;
                ans += (B - 1);
            }
            else if((A * k) - (B*( k -1)) < h)
                A++;
        }

       
    }
    cout << ans << endl;
}

int32_t main()
{

    int t;
    cin >> t;

    while (t--)
    {
        func();
    }
    return 0;
}