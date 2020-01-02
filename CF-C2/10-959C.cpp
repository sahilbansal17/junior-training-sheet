#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int n;
    cin >> n;

    // tree for incorrect answer
    if (n < 6) {
        cout << "-1" << endl; // no case for incorrect answer
    } else {
        // connect 1 with 2, 3, 4
        for (int i = 2; i <= 4; ++i) {
            cout << "1 " << i << endl;
        }
        // connect rest of the nodes with 2
        for (int i = 5; i <= n; ++i) {
            cout << "2 " << i << endl;
        }
        // the correct answer is |{1, 2}| = 2
        // but the algo produces min(3, n - 3) = 3 for n >= 6
    }
    // tree for correct answer
    // correct answer always produced by the algo when 1 connected to all others
    for (int i = 0; i < n - 1; ++i) {
        cout << "1 " << i + 2 << endl;
    }
    return 0;
}