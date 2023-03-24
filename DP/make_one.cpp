// Baekjoon
// 1463 1로 만들기

#include <iostream>

int ans[1000000][3];

int main()
{
	// input
	int N;
	int res;

	std::cin >> N;
	// solution
	int i = 1;
	ans[0][0] = ans[0][1] = ans[0][2] = N;
	while(1)
	{
		for (int j=0;j<3;++j)
		{
			if (ans[i-1][j] % 3 == 0)
				ans[i-1][0] = ans[i-1][j] / 3;
		}
	}
}