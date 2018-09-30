#include <bits/stdc++.h>
using namespace std;

#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl

int main() {

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	freopen("/Users/sahilbansal/Desktop/error.txt", "w",stderr);
	#endif

	string s;
	int m;
	cin >> s;
	cin >> m;

	int n = s.length();
	vector <int> ct[3];
	for (int i = 0; i < n; i++) {
		if (s[i] == 'x') {
			if (ct[0].size() == 0) {
				ct[0].push_back(1);
			}
			else {
				ct[0].push_back(ct[0][ct[0].size() - 1] + 1);
			}
			if (ct[1].size() == 0) {
				ct[1].push_back(0);
			}
			else {
				ct[1].push_back(ct[1][ct[1].size() - 1]);
			}
			if (ct[2].size() == 0) {
				ct[2].push_back(0);
			}
			else {
				ct[2].push_back(ct[2][ct[2].size() - 1]);
			}
		}
		else if (s[i] == 'y') {
			if (ct[1].size() == 0) {
				ct[1].push_back(1);
			}
			else {
				ct[1].push_back(ct[1][ct[1].size() - 1] + 1);
			}
			if (ct[0].size() == 0) {
				ct[0].push_back(0);
			}
			else {
				ct[0].push_back(ct[0][ct[0].size() - 1]);
			}
			if (ct[2].size() == 0) {
				ct[2].push_back(0);
			}
			else {
				ct[2].push_back(ct[2][ct[2].size() - 1]);
			}
		}
		else {
			if (ct[2].size() == 0) {
				ct[2].push_back(1);
			}
			else {
				ct[2].push_back(ct[2][ct[2].size() - 1] + 1);
			}
			if (ct[0].size() == 0) {
				ct[0].push_back(0);
			}
			else {
				ct[0].push_back(ct[0][ct[0].size() - 1]);
			}
			if (ct[1].size() == 0) {
				ct[1].push_back(0);
			}
			else {
				ct[1].push_back(ct[1][ct[1].size() - 1]);
			}
		}
	}

	int l, r;
	for (int i = 0; i < m; i++) {
		cin >> l >> r;

		if (r - l + 1 < 3) {
			cout << "YES" << endl;
			continue;
		}

		int cnt_x = 0, cnt_y = 0, cnt_z = 0;
		if (l == 1){
			cnt_x = ct[0][r - 1];
			cnt_y = ct[1][r - 1];
			cnt_z = ct[2][r - 1];
		}
		else{
			cnt_x = ct[0][r - 1] - ct[0][l - 2];  
			cnt_y = ct[1][r - 1] - ct[1][l - 2];  
			cnt_z = ct[2][r - 1] - ct[2][l - 2];  
		}
		// trace3(cnt_x, cnt_y, cnt_z);
		int maxi = cnt_x, mini = cnt_x;
		if (cnt_y > maxi) {
			maxi = cnt_y;
		}
		if (cnt_y < mini) {
			mini = cnt_y;
		}
		if (cnt_z > maxi) {
			maxi = cnt_z;
		}
		if (cnt_z < mini) {
			mini = cnt_z;
		}
		if (maxi - mini <= 1) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
		cout << endl;
	}

	return 0;
}