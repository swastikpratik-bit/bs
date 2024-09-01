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

vector<int> isPrime(200 + 3 , 1);

void super(int test, int totTest)
{
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> ind[101];

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        ind[A[i]].push_back(i + 1);
    }

    int got = 0;
    for (int i = 1; i <= 100 && !got; ++i) {
        for (int j = 1; j <= 100 && !got; ++j) {
            if (i != j && !ind[i].empty() && !ind[j].empty() && !isPrime[i + j]) {
                cout << ind[i][0] << " " << ind[j][0] << endl;
                return;
            }
            if (!ind[i].empty() && ind[i].size() > 1 && !isPrime[i + i]) {
                cout << ind[i][0] << " " << ind[i][1] << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= 200; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= 200; j += i) {
                    isPrime[j] = false;
                }
            }
        }

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