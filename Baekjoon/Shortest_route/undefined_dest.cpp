// Baekjoon
// 9370 미확인 도착지

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define	INF	999999999
#define MAX	2010

int	n, m, t, s, g, h;
int	dist_s[MAX];
int	dist_g[MAX];
int	dist_h[MAX];

std::vector<std::pair<int, int>>	adj[MAX];
std::vector<int>					dest;

void	init()
{
	for (int i=0;i<MAX;++i) {
        if (!adj[i].empty())
		    adj[i].clear();
		dist_s[i] = INF;
		dist_g[i] = INF;
		dist_h[i] = INF;
	}
    if (!dest.empty())
	    dest.clear();
}

void	dijkstra(int s, int dist[MAX])
{
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
}

int	main()
{
	// input
	int	T;
	std::cin >> T;
	for (int tt=1;tt<=T;++tt) {
		// input
		init();
		std::cin >> n >> m >> t;
		std::cin >> s >> g >> h;

		for (int i=0;i<m;++i) {
			int	u, v, w;
			std::cin >> u >> v >> w;
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}
		for (int i=0;i<t;++i) {
			int	tmp;	std::cin >> tmp;
			dest.push_back(tmp);
		}

		// solution
		dijkstra(s, dist_s);
		dijkstra(g, dist_g);
		dijkstra(h, dist_h);
		int	gh = dist_g[h];
		std::sort(dest.begin(), dest.end());
		for (auto a : dest) {
			if (dist_s[a] == dist_s[g] + gh + dist_h[a]
				|| dist_s[a] == dist_s[h] + gh + dist_g[a])
				std::cout << a << ' ';
		}
		std::cout << '\n';
	}

	return (0);
}