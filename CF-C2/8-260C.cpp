/*
 * Problem Link: https://codeforces.com/contest/260/problem/C
 */

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

    // find the possible min from multiple of them
    
    bool toLeft = false;
    for (int i = 0; i <= x; ++i) {
        if (a[i] == minVal) {
            toLeft = true;
        }
    }
    if (a[x] == minVal) {
        minIdx = x;
    } else if (!toLeft) {
        // find the rightmost minIdx, since no more minVals after it
        for (int i = n - 1; i >= x + 1; --i) {
            if (a[i] == minVal) {
                minIdx = i;
                break;
            }
        }
    } else {
        // find the leftmost minIdx to x
        for (int i = x - 1; i >= 0; --i) {
            if (a[i] == minVal) {
                minIdx = i;
                break;
            }
        }
    }

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
        for (int i = 0; i <= x; ++i) {
            a[i] -= (minVal + 1);
        }
        for (int i = x + 1; i < minIdx; ++i) {
            a[i] -= minVal;
        }
        for (int i = minIdx + 1; i < n; ++i) {
            a[i] -= (minVal + 1);
        }
        a[minIdx] = (minIdx - x)*minVal + (n - (minIdx - x))*(minVal + 1);
    } else {
        for (int i = minIdx + 1; i <= x; ++i) {
            a[i] -= (minVal + 1);
        }
        for (int i = 0; i < minIdx; ++i) {
            a[i] -= minVal;
        }
        for (int i = x + 1; i < n; ++i) {
            a[i] -= minVal;
        }
        a[minIdx] = (x - minIdx)*(minVal + 1) + (n - (x - minIdx))*minVal;
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}