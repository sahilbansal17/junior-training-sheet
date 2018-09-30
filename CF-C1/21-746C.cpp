#include <bits/stdc++.h>

using namespace std;

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w",stderr);
    #endif

	int s, x1, x2;
	cin >> s >> x1 >> x2;

	int t1, t2;
	cin >> t1 >> t2;

	int p, d;
	cin >> p >> d;

	int all_walk = abs(x2 - x1) * t2;

	int all_tram;
	if (x1 > x2) {
		x1 = s - x1;
		x2 = s - x2;
		p  = s - p;
		d  = -d;
	}

	if (d == 1 && x1 < p) {
		all_tram = t1 * (s * 2 + (x2 - p));
	}
	else if (d == -1) {
		all_tram = t1 * (x2 + p);
	}
	else {
		all_tram = t1 * (x2 - p);
	}

	cout << min(all_tram, all_walk) << endl;
	return 0;
}