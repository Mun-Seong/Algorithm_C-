// Baekjoon
// 11066 파일 합치기

#include <iostream>
#include <cstring>

int	t, k;
int	cost[501];
int	sum[501];
int	dp[501][501];

int	dp_f(int start, int end)
{
	if (dp[start][end] != 0x3f3f3f3f)
		return (dp[start][end]);
	if (start == end)
		return (dp[start][end] = 0);
	for (int mid=start;mid<end;++mid) {
		int l = dp_f(start, mid);
		int r = dp_f(mid+1, end);
		dp[start][end] = std::min(dp[start][end], l + r);
	}
	return (dp[start][end] += sum[end] - sum[start-1]);
}

int	main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	// input
	std::cin >> t;

	for (int i=0;i<t;++i) {
		// input
		std::cin >> k;
		for (int j=1;j<=k;++j) {
			std::cin >> cost[j];
			sum[j] = sum[j-1] + cost[j];
		}
		// solution
		memset(dp, 0x3f, sizeof(dp));
		std::cout << dp_f(1, k) << '\n';
	}

	return (0);
}
