// Baekjoon
// 1753 최단경로

#include <iostream>
#include <vector>
#include <queue>

#define	INF	99999
typedef std::vector<std::pair<int, int>>	vpii;
//	vector[start] = {end, weight}
int		V, E, start;
vpii	graph[20001];
bool	vis[20001];

std::vector<int>	dijkstra(int s) {
	std::vector<int>	dist(V+1, INF);
	dist[s] = 0;
	std::priority_queue<std::pair<int, int>>	pq;
	pq.push({0, s});

	while (!pq.empty()) {
		int	w = -pq.top().first;
		int	v = pq.top().second;
		pq.pop();

		if (dist[v] < w)	continue;

		for (auto a : graph[v]) {
			int	vv = a.first;
			int	ww = w + a.second;
			if (dist[vv] > ww) {
				dist[vv] = ww;
				pq.push({-ww, vv});
			}
		}
	}
	return (dist);
}

int	main()
{
	// input
	std::cin >> V >> E >> start;
	for(int i=0;i<E;++i) {
		int	u, v, w;
		std::cin >> u >> v >> w;
		graph[u].push_back({v, w});
	}

	// solution
	std::vector<int>	dist = dijkstra(start);

	for (int i=1;i<=V;++i) {
		if (dist[i] == INF)
			std::cout << "INF" << '\n';
		else
			std::cout << dist[i] << '\n';
	}
	return (0);
}