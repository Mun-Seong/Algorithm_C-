// Baekjoon
// 1012 유기농 배추

#include <iostream>
#include <cstring>

int		t, m, n, k;
bool	arr[51][51];
bool	vis[51][51];

void	dfs(int i, int j)
{
	static	int di[4] = {1, -1, 0, 0};
	static	int dj[4] = {0, 0, 1, -1};
	for (int a=0;a<4;++a) {
		int	ii = i + di[a];
		int jj = j + dj[a];
		if (ii < 0 || ii >= n || jj < 0 || jj >=m)
			continue;
		if (!vis[ii][jj] && arr[ii][jj]) {
			vis[ii][jj] = true;
			dfs(ii, jj);
		}
	}

}

int	main()
{
	// input
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> t;
	for (int tt=0;tt<t;++tt) {
		// init
		int	ans = 0;
		memset((void*)arr, 0, sizeof(arr));
		memset((void*)vis, 0, sizeof(vis));

		// input
		std::cin >> m >> n >> k;
		for (int i=0;i<k;++i) {
			int	x, y;
			std::cin >> x >> y;
			arr[y][x] = true;
		}

		// solution
		for (int i=0;i<n;++i) {
			for (int j=0;j<m;++j) {
				if (arr[i][j] && !vis[i][j]) {
					dfs(i, j);
					ans++;
				}
			}
		}

		std::cout << ans << '\n';
	}
	return (0);
}