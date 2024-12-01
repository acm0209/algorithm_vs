#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool palindrome(string s) {
	int size = s.size();
	for (int i = 0; i < size / 2; ++i) {
		if (s[i] != s[size - i - 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;

	string s;
	vector<string> v;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		v.push_back(s);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			if (palindrome(v[i] + v[j])) {
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";

	return 0;
}