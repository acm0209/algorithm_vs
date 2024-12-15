#include<iostream>

using namespace std;

int main()
{
	int N;
	char c1, c2;
	cin >> N >> c1 >> c2;

	string s;
	cin >> s;

	for (int i = 0;i < N;++i)
	{
		if (s[i] == c1) continue;
		s[i] = c2;
	}
	cout << s;

	return 0;
} 