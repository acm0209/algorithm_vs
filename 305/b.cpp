#include <iostream>

using namespace std;

int dist[] = { 3, 1, 4, 1, 5, 9 };

int main() {
	char p, q;
	cin >> p >> q;

	int int_p = p - 'A';
	int int_q = q - 'A';

	int sub = 0;
	for (int i = 0; i < int_p; ++i) {
		sub += dist[i];
	}
	int sum = 0;
	for (int i = 0; i < int_q; ++i) {
		sum += dist[i];
	}
	cout << abs(sum - sub);

	return 0;
}