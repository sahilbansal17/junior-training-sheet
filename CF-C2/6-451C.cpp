#include <iostream>
#include <assert.h>
using namespace std;
typedef long long ll;
int main () {
    int t;
    cin >> t;
    while (t--) {
        ll n, k, d1, d2;
        cin >> n >> k >> d1 >> d2;
        
        if (n % 3 != 0) {
            cout << "no" << endl;
            continue;
        }

        ll w1, w2, w3, end;
        end = n/3;
        // w1 >= w2 and w2 >= w3
        if ((-2*d2 + k - d1) % 3 == 0) {
            w3 = (-2*d2 + k - d1)/3;
            w2 = d2 + w3;
            w1 = d1 + w2;
            end = n/3;
            if (w1 >= 0 && w2 >= 0 && w3 >= 0 && w1 <= k && w2 <= k && w3 <= k &&
                w1 >= w2 && w2 >= w3 && w1 <= end && w2 <= end && w3 <= end) {
                assert(abs(w1 - w2) == d1);
                assert(abs(w2 - w3) == d2);
                assert(w1 + w2 + w3 == k);
                cout << "yes" << endl;
                continue;
            }
        }
        // w1 >= w2 and w2 <= w3
        if ((2*d2 + k - d1) % 3 == 0) {
            w3 = (2*d2 + k - d1)/3;
            w2 = w3 - d2;
            w1 = w2 + d1;
            if (w1 >= 0 && w2 >= 0 && w3 >= 0 && w1 <= k && w2 <= k && w3 <= k && 
                w1 >= w2 && w2 <= w3 && w1 <= end && w2 <= end && w3 <= end) {
                assert(abs(w1 - w2) == d1);
                assert(abs(w2 - w3) == d2);
                assert(w1 + w2 + w3 == k);
                cout << "yes" << endl;
                continue;
            }
        }

        // w1 <= w2 and w2 >= w3
        if ((-2*d2 + k + d1) % 3 == 0) {
            w3 = (-2*d2 + k + d1)/3;
            w2 = w3 + d2;
            w1 = w2 - d1;
            if (w1 >= 0 && w2 >= 0 && w3 >= 0 && w1 <= k && w2 <= k && w3 <= k &&
                w1 <= w2 && w2 >= w3 && w1 <= end && w2 <= end && w3 <= end) {
                assert(abs(w1 - w2) == d1);
                assert(abs(w2 - w3) == d2);
                assert(w1 + w2 + w3 == k);
                cout << "yes" << endl;
                continue;
            }
        }

        // w1 <= w2 and w2 <= w3
        if ((2*d2 + k + d1) % 3 == 0) {
            w3 = (2*d2 + k + d1)/3;
            w2 = w3 - d2;
            w1 = w2 - d1;
            if (w1 >= 0 && w2 >= 0 && w3 >= 0 && w1 <= k && w2 <= k && w3 <= k &&
                w1 <= w2 && w2 <= w3 && w1 <= end && w2 <= end && w3 <= end) {
                assert(abs(w1 - w2) == d1);
                assert(abs(w2 - w3) == d2);
                assert(w1 + w2 + w3 == k);
                cout << "yes" << endl;
                continue;
            }
        }

        cout << "no" << endl;
    }
}