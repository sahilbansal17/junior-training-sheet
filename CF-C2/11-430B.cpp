/*
 * Problem Link: https://codeforces.com/problemset/problem/430/B
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int n, k, x;
    cin >> n >> k >> x;

    vector<int> c(n);
    for (auto &col: c) {
        cin >> col;
    }

    int max_destroyed = 0;
    for (int i = 0; i <= n; ++i) {
        int cur_destroyed = 0;
        vector<int> temp = c;
        temp.insert(temp.begin() + i, x);
        bool more = true;
        vector<int> marked(n + 1, 0);

        while (more) {
            int sz = temp.size();
            int consecutive_count = 0;
            int prev = -1;
            bool done = false;
            for (int i = 0; i < sz; ++i) {
                if (marked[i]) {
                    continue;
                }
                if (temp[i] == prev) {
                    ++consecutive_count;
                }
                if (temp[i] != prev || i == sz - 1) {
                    if (consecutive_count >= 3) {
                        // cout << consecutive_count << endl;
                        cur_destroyed += consecutive_count;
                        done = true;
                        int j = i - 1;
                        while (j >= 0 && (temp[j] == prev || marked[j] == 1)) {
                            marked[j] = 1;
                            --j;
                        }
                    }
                    prev = temp[i];
                    consecutive_count = 1;
                }
            }
            if (!done) {
                more = false;
            }
        }
        // cout << cur_destroyed << endl;
        if (cur_destroyed > max_destroyed) {
            max_destroyed = cur_destroyed;
        }
    }
    max_destroyed = (max_destroyed > 0) ? --max_destroyed : 0;
    cout << max_destroyed << endl;
    return 0;
}