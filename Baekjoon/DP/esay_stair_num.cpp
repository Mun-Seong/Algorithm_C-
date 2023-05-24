// Baekjoon
// 10844 쉬운 계단 수

#include <iostream>

int ans[101][10];

int main()
{
	// input
	int	N;
	int res(0);
	std::cin >> N;
	// solution
	for (int i=1;i<10;i++)
		ans[1][i] = 1;
	for (int i=2; i<=N; ++i)
	{
		for (int j=0;j<10;++j)
		{
			if (j == 0)
				ans[i][0] = ans[i-1][j+1];
			else if (j == 9)
				ans[i][9] = ans[i-1][j-1];
			else
				ans[i][j] = ans[i-1][j+1] + ans[i-1][j-1];
			ans[i][j] %= 1000000000;
		}
	}
	for (int i=0;i<10;++i)
		res = (res + ans[N][i]) % 1000000000;
	std::cout << res << std::endl;
}