// Baekjoon
// 1504 특정한 최단 경로

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define	INF	999999999

int	V, E, v1 ,v2;
std::vector<std::pair<int, int>>	adj[801];
//	vector[start] = {end, weight}

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

		for (auto a : adj[v]) {
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

int	main() {
	// input
	std::cin >> V >> E;
	for (int i=0;i<E;++i) {
		int	u, v, w;
		std::cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	std::cin >> v1 >> v2;

	// solution	= 1 -> v1 -> v2 -> N || 1 -> v2 -> v1 -> N
	std::vector<int>	s1 = dijkstra(1);
	std::vector<int>	sv1 = dijkstra(v1);
	std::vector<int>	sv2 = dijkstra(v2);

	int	ans = -1;
	if (s1[V] != INF)
		ans = std::min(s1[v1] + sv1[v2] + sv2[V], s1[v2] + sv2[v1] + sv1[V]);
	std::cout << ans << '\n';

	return (0);
}