// Baekjoon
// 7579 앱

#include <iostream>
#include <algorithm>

int	n, m, sum;
int	mem[101], cost[101];
int	dp[101][10001];

int	main()
{
	// input
	std::cin >> n >> m;
	for (int i=1;i<=n;++i)
		std::cin >> mem[i];
	for (int i=1;i<=n;++i) {
		std::cin >> cost[i];
		sum += cost[i];
	}
	
	// solution
	for (int i=1;i<=n;++i) {
		for (int j=0;j<=sum;++j) {
			if (j - cost[i] >= 0)
				dp[i][j] = std::max(dp[i][j], dp[i-1][j-cost[i]] + mem[i]);
			dp[i][j] = std::max(dp[i][j], dp[i-1][j]);
		}
	}
	for (int i=0;i<=sum;++i)
	{
		if (dp[n][i] >= m) {
			std::cout << i << '\n';
			return (0);
		}
	}
}