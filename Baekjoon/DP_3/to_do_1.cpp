// Baekjoon
// 1311 할 일 정하기 1

// 참고 https://zzonglove.tistory.com/43

#include <iostream>
#include <algorithm>
#include <cstring>

int	inf = 999999999;

int	n;
int	d[20][20];
int	dp[20][1 << 20];

int	dfs(int cur, int state)
{
	int	&ret = dp[cur][state];

	if (state == (1 << n) - 1)	return (0);
	if (ret != -1)				return (ret);

	int	ans = 1e9;
	for (int i=0;i<n;++i) {
		if ((state & (1 << i)) == 0) {
			ans = std::min(ans, dfs(cur + 1, state | (1 << i)) + d[cur][i]);
		}
	}
	return (ret = ans);
}

int	main()
{
	// input
	std::cin >> n;
	for (int i=0;i<n;++i) {
		for (int j=0;j<n;++j) {
			std::cin >> d[i][j];
		}
	}

	// solution
	memset(dp, -1, sizeof(dp));
	std::cout << dfs(0, 0) << '\n';

	return (0);
}