#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = 0; j < 7; ++j) {
			int step;
			cin >> step;
			sum += step;
		}
		ans.push_back(sum);
	}

	for (int i = 0; i < n; ++i) {
		cout << ans[i] << ' ';
	}

	return 0;
}