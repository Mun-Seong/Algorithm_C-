// Baekjoon
// 2098번 외판원 순회

#include <iostream>
#include <algorithm>

int	n, w[16][16];
int	dp[16][1 << 16];

int	tsp(int cur, int state)
{
	int	&ret = dp[cur][state];

	if (state == (1 << n) - 1) {
		if (w[cur][0] > 0)
			return (w[cur][0]);
		else
			return (1e9);
	}
	if (ret != 0)	return (ret);

	ret = 1e9;
	for (int i=0;i<n;++i) {
		if (w[cur][i] == 0)	continue;
		if ((state & (1 << i)) == 0) {
			ret = std::min(ret, tsp(i, state | (1 << i)) + w[cur][i]);
		}
	}
	return (ret);
}

int	main()
{
	// input
	std::cin >> n;
	for (int i=0;i<n;++i)
		for (int j=0;j<n;++j)
			std::cin >> w[i][j];

	// solution - 순환하는 경로이기 때문에 한 점에서만 판단 가능
	std::cout << tsp(0, 1) << '\n';
	
	return (0);
}