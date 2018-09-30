#include <bits/stdc++.h>

using namespace std;

int32_t main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	freopen("/Users/sahilbansal/Desktop/error.txt", "w",stderr);
	#endif

	int n, time_1, time_2;
	cin >> n;

	vector <int> semifinal_1, semifinal_2;
	for (int i = 0; i < n; i++) {
		cin >> time_1 >> time_2;
		semifinal_1.push_back(time_1);
		semifinal_2.push_back(time_2);
	}

	vector <char> res1(n, '0'), res2(n, '0');
	for (int i = 0; i < n/2; i++) {
		res1[i] = '1';
		res2[i] = '1';
	}

	int i = 0, j = 0, ct = 0;
	while (i < n && j < n && ct < n) {
		if (semifinal_1[i] < semifinal_2[j]) {
			res1[i] = '1';
			i ++;
		}
		else if (semifinal_1[i] > semifinal_2[j]){
			res2[j] = '1';
			j ++;
		}
		ct ++;
	}

	for (int i = 0; i < n; i++) {
		cout << res1[i];
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << res2[i];
	}
	return 0;
}