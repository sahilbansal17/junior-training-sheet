#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main () {
    ll n, x;
    cin >> n >> x;

    --x; // zero-based
    vector<ll> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll minIdx = min_element(a.begin(), a.end()) - a.begin();
    ll minVal = a[minIdx];

    // minimum element does some magic here!
    if (x == minIdx) {
        for (int i = 0; i < n; ++i) {
            if (i != x) {
                a[i] -= minVal;
            } else {
                a[i] = n*minVal;
            }
        }
    } else if (x < minIdx) {
        int i = 0;
        ll resulting = 0;
        while (i != x) {
            a[i] -= (minVal + 1);
            resulting += (minVal + 1);
            ++i;
        }
        a[i] -= (minVal + 1); // i == x
        resulting += (minVal + 1);
        ++i;
        while (i != minIdx) {
            a[i] -= (minVal);
            resulting += (minVal);
            ++i; 
        }
        resulting += minVal; // to maintain at i == minIdx
        ++i; // i == minIdx;
        while (i < n) {
            a[i] -= (minVal + 1);
            resulting += (minVal + 1);
            ++i;
        }
        a[minIdx] = resulting;
    } else {
        ll resulting = 0;
        for (int idx = minIdx + 1; idx <= x; ++idx) {
            a[idx] -= (minVal + 1);
            resulting += (minVal + 1);
        }
        for (int i = 0; i < minIdx; ++i) {
            a[i] -= (minVal);
            resulting += minVal;
        }
        for (int i = x + 1; i < n; ++i) {
            a[i] -= minVal;
            resulting += minVal;
        }
        resulting += minVal; // for minVal itself
        a[minIdx] = resulting;
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
