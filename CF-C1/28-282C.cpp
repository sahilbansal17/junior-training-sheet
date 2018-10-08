#include <bits/stdc++.h>

using namespace std;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w",stderr);
    #endif

    string a, b;

    cin >> a >> b;

    // lets see all possible transformations

    // 11 -> 10 
    // 11 -> 01 
    // 01 -> 11
    // 10 -> 11
    // 00 -> 00

    int l1 = a.length();
    int l2 = b.length();

    // unequal length
    if (l1 != l2) {
        cout << "NO" << endl;
        return 0;
    }

    // we can not convert anything to all zeroes
    // except when a = all zeroes
    // also the all zeroes can't be converted to anything else

    // all other conversions are possible

    int cnt_one_a = 0, cnt_one_b = 0;
    for (int i = 0; i < l1; i ++) {
        if (a[i] == '1') {
            cnt_one_a ++;
        } 
        if (b[i] == '1') {
            cnt_one_b ++;
        }
    }

    bool res = true;
    if (cnt_one_a != 0 && cnt_one_b == 0) {
        res = false;
    }
    if (cnt_one_a == 0 && cnt_one_b != 0) {
        res = false;
    }

    if (res) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}