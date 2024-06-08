#include <bits/stdc++.h>
#define int long long
using namespace std;


void func(){
    int n,f, k;
    cin >> n >> f >> k;
    int fav = -1;
    vector<int> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
        if (i + 1 == f)
        {
            fav = a[i];
        }
    }

    sort(a.rbegin(), a.rend());
    k--;
    int lastFav = -1;
    int firstFav = -1;
    for (int i = 0; i < n; i++)
    {
        if(firstFav == -1 && a[i] == fav){
            firstFav = i;
        }
        if(a[i] == fav){
            lastFav = i;
        }
    }

    // cout << firstFav << " " << lastFav << endl;

    if(k >= firstFav && k < lastFav ){
        if(lastFav == firstFav){
            cout << "YES" << endl;
        }
        else{
            cout << "MAYBE" << endl;
        }
    }
    else if(lastFav > k){
        cout << "NO" << endl;
    }
    else if(lastFav <= k){
        cout << "YES" << endl;
    }

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