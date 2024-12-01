#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> grid;            // 쿠키
vector<int> num_row_cookie;     // 각 행의 쿠키 개수
vector<int> num_column_cookie;  // 각 열의 쿠키 개수

int main() {
	int h, w;
	cin >> h >> w;

	//사각형이기 때문에, 한 행 에 같은 수의 #이 있어야 함을 이용해 코드 작성
	string s;
	int row_max_cookie = 0;
	for (int i = 0; i < h; ++i) {
		cin >> s;
		grid.push_back(s);
		int tmp = 0;
		for (int j = 0; j < w; ++j) {
			if (s[j] == '#') {
				++tmp;
			}
		}
		num_row_cookie.push_back(tmp);
		row_max_cookie = max(row_max_cookie, tmp);
	}

	int column_max_cookie = 0;
	for (int i = 0; i < w; ++i) {
		int tmp = 0;
		for (int j = 0; j < h; ++j) {
			if (grid[j][i] == '#') tmp++;
		}
		column_max_cookie = max(column_max_cookie, tmp);
		num_column_cookie.push_back(tmp);
	}

	// 각 행의 # 개수를 저장해서 max 의 개수보다 1이 작은 행을 찾고 ( 행위치 찾기
	// 성공)
	int ans_row = -1;
	for (int i = 0; i < h; ++i) {
		if (num_row_cookie[i] == row_max_cookie - 1) {
			ans_row = i;
			break;
		}
	}

	// 각 열의 # 개수를 저장해서 max 의 개수보다 1이 작은 열을 찾는다 ( 열위치
	// 찾기 성공)
	int ans_column = -1;
	for (int i = 0; i < w; ++i) {
		if (num_column_cookie[i] == column_max_cookie - 1) {
			ans_column = i;
			break;
		}
	}

	cout << ans_row + 1 << ' ' << ans_column + 1 << '\n';

	return 0;
}