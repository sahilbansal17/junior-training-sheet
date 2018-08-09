#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n; // number of digits
	cin >> n;

	string s; // the number a
	cin >> s;

	// convert number from a to x using the table of conversion
	string table[10] = {"", "", "2", "3", "223", "5", "53", "7", "7222", "7332"};

	string res; // the result x
	for(int i = 0; i < n; i++){
		res += table[s[i] - '0'];
	}

	sort(res.begin(), res.end());
	
	// now reverse to find the largest possible x
	reverse(res.begin(), res.end());
	
	cout << res;
	return 0;
}
