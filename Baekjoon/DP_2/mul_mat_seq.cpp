// Baekjoon
// 11049 행렬 곱셈 순서

#include <iostream>
#include <algorithm>

// typedef std::pair<int, int>	pi;

int n;
int	size[501][2];
int	dp[501][501];

int	main()
{
	// input
	std::cin >> n;
	for (int i=1;i<=n;++i) {
		std::cin >> size[i][0] >> size[i][1];
	}

	// solution :
	// dp[a][b] = dp[a][m] + dp[m+1][b] + x;
	// x = size[a][0] * size[m][1](=size[b][0]) * size[b][1]
	for (int d=1;d<=n;++d) {
		for (int a=1;a<=n-d;++a) {
			int	b = a + d;
			if (b == a)
				continue ;
			dp[a][b] = INT32_MAX;
			for (int m=a;m<b;++m)
				dp[a][b] = std::min(dp[a][b],
					dp[a][m] + dp[m+1][b] +
					(size[a][0] * size[m][1] *size[b][1]));
		}
	}
	std::cout << dp[1][n] << '\n';
	return (0);
}