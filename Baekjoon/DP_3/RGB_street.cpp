// Baekjoon
// 17404 RGB거리 2

#include <iostream>
#include <algorithm>

int	inf = 999999999;

int	n;
int	color[1001][3];
int	dp[1001][3];

int	main()
{
	// input
	std::cin >> n;
	for (int i=1;i<=n;++i)
		std::cin >> color[i][0] >> color[i][1] >> color[i][2];

	// solution
	int	ans = inf;
	for (int s=0;s<3;++s) {
		for (int i=0;i<3;++i) {
			if (i == s)	dp[1][i] = color[1][i];
			else		dp[1][i] = inf;
		}
		for (int i=2;i<=n;++i) {
			dp[i][0] = std::min(dp[i-1][1], dp[i-1][2]) + color[i][0];
			dp[i][1] = std::min(dp[i-1][0], dp[i-1][2]) + color[i][1];
			dp[i][2] = std::min(dp[i-1][0], dp[i-1][1]) + color[i][2];
		}
		for (int i=0;i<3;++i) {
			if (i == s)	continue;
			// s != e
			ans = std::min(ans, dp[n][i]);
		}
	}
	std::cout << ans << '\n';

	return (0);
}