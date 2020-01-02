#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

template<typename T> 
T gcd(T a, T b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    FAST_IO;

    int n;
    cin >> n;

    set<int> s;
    int x;
    int d;
    int maxi = INT_MIN;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        s.insert(x);
        if (x > maxi) {
            maxi = x;
        }
        if (i == 1) {
            vector<int> a;
            for (auto elem: s) {
                a.push_back(elem);
            }
            d = gcd(a[0], a[1]);
        } else if (i > 1) {
            d = gcd(d, x);
        }
    }

    int cnt = (maxi/d) - s.size();
    if (cnt & 1) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }

    return 0;
}