// Baekjoon
// 4803 트리

#include <iostream>
#include <vector>
#include <cstring>

int		n, m;
bool	vis[501];
std::vector<int>	graph[501];

bool	dfs(int s, int pre)
{
	vis[s] = true;
	for (int c : graph[s]) {
		if (c == pre)	continue;
		if (vis[c])	return (false);
		if (dfs(c, s) == false) return (false);
	}
	return (true);
}

int	main()
{
	int	test = 1;
	while (1) {
		// input
		std::cin >> n >> m;
		if (n == 0 && m == 0)
			break ;
		for (int i=1;i<=n;++i)	graph[i].clear();
		memset((void *)vis, 0, sizeof(vis));
		for (int i=0;i<m;++i) {
			int	s, e;
			std::cin >> s >> e;
			graph[s].push_back(e);
			graph[e].push_back(s);
		}

		// solution
		int	num(0);
		for (int i=1;i<=n;++i) {
			if (vis[i])
				continue;
			if (dfs(i, 0))
				num++;
		}

		// output
		std::cout << "Case " << test++;
		if (num == 0) std::cout << ": No trees.";
		else if (num == 1) std::cout << ": There is one tree.";
		else std::cout << ": A forest of " << num << " trees.";
		std::cout << '\n';
	}
	return (0);
}