#include<iostream>
#include<vector>

using namespace std;

long long A[500000]; // indexed tree

// indexed tree를 구성해서, 전체합으로 나눈 나머지에 대해서 구간합인(세그먼트 트리의) 값이 있는지 찾아야 한다.
int main()
{
	long long N, S;
	cin >> N >> S;

	long long base = 2 * N;
	for (long long i = 0;i < N;++i)
	{
		long long index = base + i;
		cin>>A[index];

		while (index > 1) {
			index /= 2;
			A[index] = A[index * 2] + A[index * 2 + 1];
		}
	}

	for (long long i = 0;i < 2 * N;++i) cout << A[i]<<'\n';





	return 0;
}