// Baekjoon
// 1967 트리의 지름

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

int				v, max_dist, max_node;
bool			vis[100001];
std::vector<std::pair<int, int>>	graph[100001];


void	dfs(int s, int dist)
{
	vis[s] = true;
	for (int i=0;i<graph[s].size();++i) {
		int next = graph[s][i].first;
		int	n_dist = graph[s][i].second;
		if (vis[next])
			continue ;
		else
		{
			vis[next] = true;
			if (max_dist < dist + n_dist) {
				max_dist = dist + n_dist;
				max_node = next;
			}
			dfs(next, dist + n_dist);
		}
	}
}

int	main()
{
	// input 
	std::cin >> v;
	for (int i=0;i<v-1;++i) {
		int s, e, w;
		std::cin >> s >> e >> w;
		graph[s].push_back({e, w});
		graph[e].push_back({s, w});
	}

	// solution
	dfs(1, 0);	//최대값을 찾으려며 전체 탐색이 필요
	memset((void *)vis, 0, sizeof(vis));
	dfs(max_node, 0);

	std::cout << max_dist << '\n';

	return (0);
}
