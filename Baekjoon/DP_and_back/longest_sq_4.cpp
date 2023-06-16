// Baekjoon
// 14002 가장 긴 증가하는 부분 수열 4

#include <iostream>
#include <algorithm>

int	n;
int	seq[1001];
int	dp[1001];
int	path[1001];

int	main()
{
	// input
	std::cin >> n;
	for (int i=1;i<=n;++i)
		std::cin >> seq[i];
	
	// solution
	int	res(0), max_idx(0);
	for (int i=1;i<=n;++i)
		dp[i] = 1;
	for (int i=2; i<=n; ++i)
	{
		for (int j=1;j<i;++j)
		{
			if (seq[i] > seq[j])
				dp[i] = std::max(dp[i], dp[j] + 1);
			if (dp[i] == dp[j] + 1)
				path[i] = j;
		}
	}
	for (int i=1;i<=n;++i) {
		if (res < dp[i]) {
			res = dp[i];
			max_idx = i;
		}
	}
	std::cout << res << std::endl;
	std::cout << path[max_idx] << '\n';
	while (path[max_idx] != 0) {
		std::cout << seq[max_idx] << ' ';
		max_idx = path[max_idx];
	}
	/** 거꾸로 출력 됨 수정 필요 */
	return (0);
}