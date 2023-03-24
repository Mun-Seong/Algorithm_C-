// Baekjoon
// 1932 정수 삼각형

#include <iostream>

int tri[501][501];
long long int ans[501][501];

int main()
{
	// input
	int n;
	long long int res(0);

	std::cin >> n;
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<i+1;++j)
			std::cin >> tri[i][j];
	}
	ans[1][1] = tri[1][1];

	// solution
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<i+1;++j)
		{
			int prev_max = std::max(ans[i-1][j], ans[i-1][j-1]);
			ans[i][j] = tri[i][j] + prev_max;
		}
	}
	for (int i=1;i<=n;++i)
		res = std::max(ans[n][i], res);
	std::cout << res << std::endl;

	return 0;
}