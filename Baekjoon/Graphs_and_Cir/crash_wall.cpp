// Baekjoon
// 2206 벽 부수고 이동하기

#include <iostream>
#include <string>
#include <queue>

typedef struct pos
{
	int		x, y;
	bool	has_break;
} pos;

char	arr[1001][1001];
int		vis[1001][1001][2];
int		n, m;

int	main()
{
	// input
	std::cin >> n >> m;
	for (int i=1;i<=n;++i) {
		std::string s;
		std::cin >> s;
		for (int j=1;j<=m;++j) {
			arr[i][j] = s[j-1];
		}
	}
	// solution
	int ans = -1;
	std::queue<pos>	q;
	vis[1][1][0] = true;
	q.push({1,1,0});
	while (!q.empty()) {
		pos	u = q.front();	q.pop();
		if (u.x == n && u.y == m) {
			ans = vis[n][m][u.has_break];
			break;
		}
		int	d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
		for (int i=0;i<4;++i) {
			int dr = u.x + d[i][0];
			int dc = u.y + d[i][1];
			if (!(0 < dr && dr <= n) || !(0 < dc && dc <= m))
				continue;
			if (vis[dr][dc][u.has_break]) 
				continue;
			if (arr[dr][dc] == '0') {
				vis[dr][dc][u.has_break] = vis[u.x][u.y][u.has_break] + 1;
				q.push({dr, dc, u.has_break});
			}
			if (arr[dr][dc] == '1' && u.has_break == false) {
				vis[dr][dc][1] = vis[u.x][u.y][u.has_break] + 1;
				q.push({dr, dc, true});
			}
			
		}
	}
	std::cout << ans << '\n';

	return (0);
}
