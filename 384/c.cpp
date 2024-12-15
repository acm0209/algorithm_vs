#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
	if (a.second !=b.second) return a.second > b.second;
	return a.first < b.first;
}

int main()
{
	vector<int> v;
	for (int i = 0;i < 5;++i)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}

	//vector <pair<string, int>> v;

	vector <pair<string,int>> ans;
	for (int i = 1;i < 32;++i) // 1부터 31까지 (0제외 총 31개) 비트마스킹으로 푼다. 1^0=a. 1^1=b ... 1^4=d
	{
		int val = 0;
		string s;
		for (int j = 0;j < 5;++j)
		{
			if (i & (1 << j))
			{
				val += v[j];
				if (j == 0) s += 'A';
				if (j == 1) s += 'B';
				if (j == 2) s += 'C';
				if (j == 3) s += 'D';
				if (j == 4) s += 'E';
			}
		}
		ans.push_back(pair<string, int>(s, val));
	}
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0;i < ans.size();++i)
	{
		cout << ans[i].first << '\n';
	}

	return 0;
}