// Baekjoon
// 11779 최소비용 구하기 2

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define	INF	999999999

typedef std::vector<std::pair<int, int>>	vpii;
//	vector[start] = {end, weight}
vpii	graph[20001];
int		n, m, start, dest;
int		dp[1010];

std::vector<int>	dijkstra(int s) {
	std::vector<int>	dist(n+1, INF);
	std::priority_queue<std::pair<int, int>>	pq;
	dist[s] = 0;
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
				dp[vv] = v;
				pq.push({-ww, vv});
			}
		}
	}
	return (dist);
}

int	main()
{
	// input
	std::cin >> n >> m;
	for (int i=0;i<m;++i) {
		int s, e, w;
		std::cin >> s >> e >> w;
		graph[s].push_back({e, w});
	}
	std::cin >> start >> dest;

	// solution
	std::vector<int>	path, dist;
	dist = dijkstra(start);
	std::cout << dist[dest] << '\n';
	while (dest) {
		path.push_back(dest);
		dest = dp[dest];
	}
	std::cout << path.size() << '\n'; 
	for (int i=path.size()-1;i>=0;--i)
		std::cout << path[i] << ' ';
	std::cout << '\n';

	return (0);
}