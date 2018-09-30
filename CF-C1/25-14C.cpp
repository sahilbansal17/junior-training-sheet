#include <bits/stdc++.h>

using namespace std;

int main() {
    int x = 0, y = 0;

    map< pair<int, int>, int > mp;

    for (int i = 0; i < 4; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x += (x1 == x2 && y1 != y2);
        y += (x1 != x2 && y1 == y2);
        ++mp[{x1, y1}];
        ++mp[{x2, y2}];
    } 

    int ans = (x == 2 && y == 2);
    for (auto x : mp) {
        ans &= (x.second == 2);
    }

    cout << (ans ? "YES" : "NO") << '\n';
    return 0;
}