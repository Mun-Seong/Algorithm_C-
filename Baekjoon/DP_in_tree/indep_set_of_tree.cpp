// Baekjoon
// 2213 트리의 독립집합

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

int					n;
int					w[10001];
int					dp[10001][2];
bool				vis[10001];
std::vector<int>	g[10001];
std::vector<int>	ans;

void	dfs_for_w(int cur)
{
	dp[cur][0] = 0;
	dp[cur][1] = w[cur];
	vis[cur] = true;

	for (auto next : g[cur]) {
		if (vis[next])	continue;
		dfs_for_w(next);
		dp[cur][0] += std::max(dp[next][0], dp[next][1]);
		dp[cur][1] += dp[next][0];
	}
}

void	dfs_for_v(int cur, int prev)
{
	if (dp[cur][1] > dp[cur][0] && vis[prev] == false) {
		ans.push_back(cur);
		vis[cur] = true;
	}

	for (auto next : g[cur]) {
		if (next == prev)	continue;
		dfs_for_v(next, cur);
	}
}



int	main()
{
	// input
	std::cin >> n;
	for (int i=1;i<=n;++i) {
		std::cin >> w[i];
	}
	// tree's E = V - 1 
	for (int i=1;i<n;++i) {
		int	u, v;
		std::cin >> u >> v;
		g[v].push_back(u);
		g[u].push_back(v);
	}

	//solution
	dfs_for_w(1);
	memset((void *)vis, 0, sizeof(vis));
	dfs_for_v(1, 0);

	std::sort(ans.begin(), ans.end());
	std::cout << std::max(dp[1][0], dp[1][1]) << '\n';
	for (int i : ans)
		std::cout << i << ' ';

	return (0);
}