// Baekjoon
// 11404 플로이드

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define	INF	999999999

int			n, m;
int			adj[101][101];
long long	dist[101][101];

void	Floyd(void)
{
	// init dist
	for (int i=1;i<=n;++i) {
		for (int j=1;j<=n;++j) {
			if (i == j)
				continue;
			if (adj[i][j])
				dist[i][j] = adj[i][j]; 
			else
				dist[i][j] = INF;
		}
	}
	// calculate shortest
	for (int r=1;r<=n;++r) {
		for (int i=1;i<=n;++i) {
			for (int j=1;j<=n;++j) {
				dist[i][j] = std::min(dist[i][j], dist[i][r] + dist[r][j]);
			}
		}
	}
}


int	main()
{
	// input
	std::cin >> n >> m;
	for (int i=0;i<m;++i) {
		int	u, v, w;
		std::cin >> u >> v >> w;
		if (adj[u][v])
			adj[u][v] = std::min(adj[u][v], w);
		else
			adj[u][v] = w;
	}
	// solution
	Floyd();

	// output
	for (int i=1;i<=n;++i) {
		for (int j=1;j<=n;++j) {
			if (dist[i][j] == INF)
				std::cout << 0 << ' ';
			else
				std::cout << dist[i][j] << ' ';
		}
		std::cout << '\n';
	}

	return (0);
}