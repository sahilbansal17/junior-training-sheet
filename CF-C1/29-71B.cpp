#include <bits/stdc++.h>

using namespace std;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w",stderr);
    #endif

    int n, k, t;

    cin >> n >> k >> t;

    int nkt = n * k * t, sum = 0, rem;

    // cerr << nkt << endl;
    for (int i = 1; i <= n; i ++) {
        bool done = false;
        int cval = k;
        for (int j = 0; j <= k; j ++) {
            sum += j;
            if (100 * sum <= nkt && nkt < (100 * sum) + 100) {
                done = true;
                cval = j;
                // cerr << j << endl;
                break;
            }
            sum -= j;
        }
        if (done) {
            rem = n - i;
            cout << cval << " ";
            break;
        }
        else {
            sum += k;
            cout << k << " ";
        }
    }

    for (int i = 0; i < rem; i ++) {
        cout << "0 " ;
    }

    return 0;
}