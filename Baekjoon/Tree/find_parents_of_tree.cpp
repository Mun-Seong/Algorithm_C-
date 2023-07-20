// Baekjoon
// 11725 트리의 부모 찾기

#include <iostream>
#include <algorithm>
#include <vector>

int					n;
std::vector<int>	graph[100001];
int					ans[100001];

void	dfs(int node)
{
	for (int i=0;i<graph[node].size();++i) {
		int next = graph[node][i];
		if (ans[next] == 0) {
			ans[next] = node;
			dfs(next);
		}
	}
}

int	main()
{
	// input
	std::cin >> n;
	for (int i=0;i<n-1;++i) {
		int	node, parent;
		std::cin >> node >> parent;
		graph[node].push_back(parent);
		graph[parent].push_back(node);
	}
	
	// solution
	dfs(1);
	for (int i=2;i<=n;++i)
		std::cout << ans[i] << '\n';
	
	return (0);
}