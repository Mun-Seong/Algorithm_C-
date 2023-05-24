// Baekjoon
// 1520 내리막 길

#include <iostream>
#include <cstring>

int		dp[501][501];
int		map[501][501];

int	dr[4] = {1, -1, 0, 0};
int	dc[4] = {0, 0, 1, -1};

int	m, n;

int	dfs(int r, int c)
{
	// std::cout << r << ", " << c << '\n';
	int	&tmp = dp[r][c];
	// end cond
	if (tmp != -1)
		return (tmp);
	if (r == m && c == n)
		return (tmp = 1);
	
	tmp = 0;
	for (int i=0;i<4;++i) {
		int	rr = r + dr[i];
		int cc = c + dc[i];
		if (rr <= 0 || rr > m || cc <= 0 || cc > n)
			continue ;
		// std::cout << "check[rr][cc] = " << check[rr][cc] << ' ' << rr << ", " << cc << '\n';
		if (map[rr][cc] < map[r][c]) {
			tmp += dfs(rr, cc);
		}
	}
	return (tmp);
}

int	main()
{
	// input
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> m >> n;
	for (int i=1;i<=m;++i) {
		for (int j=1;j<=n;++j) {
			std::cin >> map[i][j];
		}
	}
	// solution
	memset((void *)dp, -1, sizeof(dp));
	std::cout << dfs(1, 1) << '\n';
	return (0);
}