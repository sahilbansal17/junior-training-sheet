#include <bits/stdc++.h>

using namespace std;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w",stderr);
    #endif

    int n, k;
    cin >> n >> k;

    vector <int> a(n, 0), b(n, 0);
    vector < pair <int, int> > diff;
    for (int i = 0; i < n; i ++) {
    	cin >> a[i];
    }

    for (int i = 0; i < n; i ++) {
    	cin >> b[i];
    	diff.push_back(make_pair(b[i] - a[i], i));
    }

    sort (diff.begin(), diff.end());

    int res = 0, cnt = 0;
    for (int i = n - 1; i >= 0; i --) {
    	// cerr << diff[i].first << " " << diff[i].second << endl;
    	if (cnt < k) {
    		res += a[diff[i].second];
    		cnt ++;
    	}
    	else if (diff[i].first > 0) {
    		res += a[diff[i].second];
    	}
    	else {
    		res += b[diff[i].second];
    	}
    }

    cout << res << endl;
    return 0;
}