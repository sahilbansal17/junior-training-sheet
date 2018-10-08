#include <bits/stdc++.h>

using namespace std;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w",stderr);
    #endif

    int n;
    cin >> n;

    if (n == 1 || n == 2) {
        cout << "-1";
        return 0;
    }

    if (!(n & 1)) {
        long long sqby4 = 1ll*n*n/4;
        cout << sqby4 - 1 << " " << sqby4 + 1 << endl;
    }
    else {
        long long sq = 1ll*n*n;
        cout << (sq - 1)/2 << " " << (sq + 1)/2 << endl;
    }

    return 0;
}