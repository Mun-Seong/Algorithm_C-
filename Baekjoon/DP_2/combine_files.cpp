// Baekjoon
// 11066 파일 합치기

#include <iostream>
#include <algorithm>
#include <cstdint>

int	t, k;
int	sum[501];
int	dp[501][501];

int	main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	// input
	int	temp;
	std::cin >> t;
	for (int i=0;i<t;++i) {
		// input
		std::cin >> k;
		for (int j=1;j<=k;++j) {
			std::cin >> temp;
			sum[j] = sum[j-1] + temp;
		}
		// solution
		for (int j=1;j<k;++j) {
			int a = 1, b = j + 1;
			for (int t=0;t<k-j;++t) {
				dp[a][b] = INT32_MAX;
				for (int m=b-j;m<b;++m) {
					dp[a][b] = std::min(dp[a][b], 
							dp[a][m] + dp[m+1][b] + sum[b] - sum[a-1]);
				}
				a++;
				b++;
			}
		}
		std::cout << dp[1][k] << '\n';
	}
	return (0);
}
