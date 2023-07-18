// Baekjoon
// 11780 플로이드 2

#include <iostream>
#include <vector>
#include <algorithm>

#define	INF	999999999

int			n, m;
int			adj[101][101];
long long	dist[101][101];
int			save[101][101];

void	find_mid(int s, int e, std::vector<int> &v)
{
	if (save[s][e] == 0) {
		v.push_back(s);
		v.push_back(e);
		return ;
	}
	find_mid(s, save[s][e], v);
	v.pop_back();
	find_mid(save[s][e], e, v);
}

void	Floyd(void)
{
	// init dist
	for (int i=1;i<=n;++i) {
		for (int j=1;j<=n;++j) {
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
				if (i == j) continue;
				if (dist[i][j] > dist[i][r] + dist[r][j]) {
					dist[i][j] = dist[i][r] + dist[r][j];
					save[i][j] = r;
				}
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

	// output_1
	for (int i=1;i<=n;++i) {
		for (int j=1;j<=n;++j) {
			if (dist[i][j] == INF)
				std::cout << 0 << ' ';
			else
				std::cout << dist[i][j] << ' ';
		}
		std::cout << '\n';
	}
	// output_2
	for (int i=1;i<=n;++i) {
		for (int j=1;j<=n;++j) {
			if (dist[i][j] == INF)
				std::cout << 0;
			else {
				std::vector<int>	v_save;
				find_mid(i, j, v_save);
				std::cout << v_save.size() << ' ';
				for (auto a : v_save) std::cout << a << ' ';
			}
			std::cout << '\n';
		}
	}

	return (0);
}