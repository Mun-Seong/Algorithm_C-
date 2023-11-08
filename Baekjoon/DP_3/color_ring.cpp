// Baekjoon
// 2482 색상환

#include <iostream>
#include <algorithm>

int	mod = 1000000003;
int	n, k;

// dp[n][k] = n개 짜리 색상환 중 k개를 인접하지 않게 칠하는 경우
int	dp[1001][1001];

int	main()
{
	// input
	std::cin >> n >> k;

	// solution
	// init dp[x][0] and dp[x][1]
	for (int i=0;i<=n;++i) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	// 점화식 - dp[i][j] = dp[i-2][j-1] + dp[i-1][j];
	for (int i=2;i<=n;++i) {
		for (int j=2;j<=k;++j)
			dp[i][j] = (dp[i-2][j-1] + dp[i-1][j]) % mod;
	}
	// 원이기 때문에 i-2가 아닌 i-3으로 계산
	int ans = (dp[n-1][k] + dp[n-3][k-1]) % mod;
	std::cout << ans << '\n';

	return (0);
}