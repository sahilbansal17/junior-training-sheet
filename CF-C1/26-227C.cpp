#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// calculate a^b modulo m
ll pow (ll a, ll b, ll m) {

	ll res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a) % m;
		}
		a = (a * a) % m;
		b >>= 1;
	}

	return res;
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	freopen("/Users/sahilbansal/Desktop/error.txt", "w",stderr);
	#endif

	ll n, m;
	cin >> n >> m;

	// cerr << pow(3, n, m);
	cout << (pow(3, n, m) - 1 + m) % m << endl;

	return 0;
}