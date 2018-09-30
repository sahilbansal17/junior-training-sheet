#include <bits/stdc++.h>

using namespace std;

#define int long long
template<typename T> T gcd(T a, T b){ if(b == 0) return a; return gcd(b, a % b); }
int32_t main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	freopen("/Users/sahilbansal/Desktop/error.txt", "w",stderr);
	#endif

	int a, b;
	cin >> a >> b;

	int d = gcd(a, b);
	int lcm = (a/d) * b;

	int dasha_visits, masha_visits;
	if (a > b) {
		dasha_visits = lcm/a;
		masha_visits = lcm/b - 1;
	}
	else {
		dasha_visits = lcm/a - 1;
		masha_visits = lcm/b;
	}

	if (dasha_visits > masha_visits) {
		cout << "Dasha" << endl;
	}
	else if (dasha_visits == masha_visits) {
		cout << "Equal" << endl;
	}
	else {
		cout << "Masha" << endl;
	}
	return 0;
}