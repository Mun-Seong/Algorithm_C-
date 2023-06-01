// Baekjoon
// 11657 타임머신

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define	INF	999999999

int	V, E, v1 ,v2;
std::vector<std::pair<int, int>>	adj[501];
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
	std::vector<int>	path = dijkstra(1);

	for (int i : path) {
		if (i != INF)
			std::cout << i;
		else
			std::cout << -1;
		std::cout << '\n';
	}

	return (0);
}