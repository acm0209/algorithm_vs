#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> grid;            // ��Ű
vector<int> num_row_cookie;     // �� ���� ��Ű ����
vector<int> num_column_cookie;  // �� ���� ��Ű ����

int main() {
	int h, w;
	cin >> h >> w;

	//�簢���̱� ������, �� �� �� ���� ���� #�� �־�� ���� �̿��� �ڵ� �ۼ�
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

	// �� ���� # ������ �����ؼ� max �� �������� 1�� ���� ���� ã�� ( ����ġ ã��
	// ����)
	int ans_row = -1;
	for (int i = 0; i < h; ++i) {
		if (num_row_cookie[i] == row_max_cookie - 1) {
			ans_row = i;
			break;
		}
	}

	// �� ���� # ������ �����ؼ� max �� �������� 1�� ���� ���� ã�´� ( ����ġ
	// ã�� ����)
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