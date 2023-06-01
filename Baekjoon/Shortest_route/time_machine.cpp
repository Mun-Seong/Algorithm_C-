// Baekjoon
// 11657 타임머신

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define	INF	999999999

typedef struct edge {
	int	from;
	int	to;
	int	cost;
}	edge;

int	V, E;
std::vector<edge>	edges;

std::vector<long long>	bellman_ford(int s) {
	std::vector<long long>	dist(V+1, INF);
	dist[s] = 0;
	for (int i=1;i<=V;++i) {
		for (edge e : edges) {
			int	from = e.from;
			int	to = e.to;
			int	cost = e.cost;

			if (dist[from] == INF)	continue;
			if (dist[to] > dist[from] + cost) {
				if (i == V) {
					dist.clear();
					return (dist);
				}
				dist[to] = dist[from] + cost;
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
		edges.push_back({u, v, w});
	}
	std::vector<long long>	path = bellman_ford(1);
	if (path.empty())
		std::cout << -1 << '\n';
	else {
		for (int i=2;i<=V;++i) {
			if (path[i] != INF)
				std::cout << path[i];
			else
				std::cout << -1;
			std::cout << '\n';
		}
	}

	return (0);
}