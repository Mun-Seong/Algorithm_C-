// Baekjoon
// 2533 사회만 서비스(SNS)

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>


int					n;
int					dp[1000001][2];	// yes or no
bool				vis[1000001];
std::vector<int>	tree[1000001];

void	dfs(int	cur)
{
	vis[cur] = true;
	dp[cur][0] = 1;
	for (auto next : tree[cur]) {
		if (vis[next])	continue;
		dfs(next);
		dp[cur][0] += std::min(dp[next][0], dp[next][1]);
		dp[cur][1] += dp[next][0];
	}
}

int	main()
{
	// input
	std::cin >> n;
	for (int i=0;i<n-1;++i) {
		int	u, v;
		std::cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	// solution
	dfs(1);
	std::cout << std::min(dp[1][0], dp[1][1]) << '\n';

	return (0);
}