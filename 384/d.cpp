#include<iostream>
#include<vector>

using namespace std;

long long A[500000]; // indexed tree

// indexed tree�� �����ؼ�, ��ü������ ���� �������� ���ؼ� ��������(���׸�Ʈ Ʈ����) ���� �ִ��� ã�ƾ� �Ѵ�.
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