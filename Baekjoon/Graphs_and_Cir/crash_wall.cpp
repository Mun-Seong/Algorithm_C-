// Baekjoon
// 2206 벽 부수고 이동하기

#include <iostream>
#include <string>
#include <queue>

typedef std::pair<std::pair<int, int>, std::pair<int, bool>>	piiib;
// {{r, c}, {cnt, breakable}}

char	arr[1001][1001];
bool	vis[1001][1001];
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
	std::queue<piiib>	q;
	q.push({{1, 1}, {1, true}});
	while (!q.empty()) {
		piiib	u = q.front();	q.pop();
		if (u.first.first == n && u.first.second == m) {
			ans = u.second.first;
			break;
		}
		int	d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
		for (int i=0;i<4;++i) {
			int dr = u.first.first + d[i][0];
			int dc = u.first.second + d[i][1];
			if (!(0 < dr && dr <= n) || !(0 < dc && dc <= m))
				continue;
			if (!vis[dr][dc]) {
				if (arr[dr][dc] == '0') {
					vis[dr][dc] = true;
					q.push({{dr, dc}, {u.second.first + 1, u.second.second}});
				}
				else {
					if (u.second.second) {
						vis[dr][dc] = true;
						q.push({{dr, dc}, {u.second.first + 1, false}});
					}
				}
			}
		}
	}
	std::cout << ans << '\n';

	return (0);
}
