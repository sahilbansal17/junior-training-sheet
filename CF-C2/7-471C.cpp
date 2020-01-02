#include <iostream>
#include <math.h>
using namespace std;

typedef long long ll;

bool possible(ll mid, ll n) {
    // minimum no. of cards required to build a house with 'mid' no. of floors
    ll n_min = (3*mid*(mid + 1))/2 - mid;
    if (n_min <= n) {
        return true;
    }
    return false;
}

int main () {
    ll n;
    cin >> n;

    ll res = 0;
    for (ll f = 0; f <= sqrt(n); ++f) {
        if (possible(f, n)) {
            res = f;
        }
    }
    // this step is required to make sure (n + f) % 3 == 0
    while ((res + n) % 3) {
        --res;
    }
    // still need to understand why this is required!
    res = (res + 3 - 1)/3;
    cout << res << endl;
    return 0;
}
