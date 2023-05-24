// Baekjoon
// 7562 나이트의 이동

#include <iostream>
#include <queue>
#include <cstring>

typedef std::pair<std::pair<int, int>, int>	piii;

int		t, n, ans;
bool	board[301][301];
bool	vis[301][301];

piii	*knight(piii c)
{
	static	int	pm[4][2] = {{2,0}, {0,2}, {-2,0}, {0,-2}};
	static	int	nm[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
	piii	*ret = new piii[8];

	for (int j=0;j<4;++j) {
		int	ff = c.first.first + pm[j][0];
		int	fs = c.first.second + pm[j][1];
		if (j % 2) {
			for (int i=0;i<2;++i) {
				ret[j*2 + i].first.first = ff + nm[i][0];
				ret[j*2 + i].first.second = fs + nm[i][1];
				ret[j*2 + i].second = c.second + 1;
			}
		}
		else {
			for (int i=0;i<2;++i) {
				ret[j*2 + i].first.first = ff + nm[i+2][0];
				ret[j*2 + i].first.second = fs + nm[i+2][1];
				ret[j*2 + i].second = c.second + 1;
			}
		}
	}
	return (ret);
}

int	main()
{
	// input
	std::cin >> t;
	for (int tt=0;tt<t;++tt) {
		// init
		memset((void *)vis, 0, sizeof(vis));
		memset((void *)board, 0, sizeof(board));
		piii	s, e;
		s.second = 0;

		std::cin >> n >> s.first.first >> s.first.second
				>> e.first.first >> e.first.second;
		
		// solution
		std::queue<piii>	q;
		q.push(s);
		vis[s.first.first][s.first.second] = true;
		while (!q.empty()) {
			piii	u = q.front();
			q.pop();
			if (u.first.first == e.first.first
				&& u.first.second == e.first.second) {
				ans = u.second;
				break;
			}

			piii	*go = knight(u);
			for (int i=0;i<8;++i) {
				if (vis[go[i].first.first][go[i].first.second]
					|| !(0 <= go[i].first.first && go[i].first.first < n)
					|| !(0 <= go[i].first.second && go[i].first.second < n))
					continue;
				vis[go[i].first.first][go[i].first.second] = true;
				q.push(go[i]);
			}
		}
		std::cout << ans << '\n';
	}
	return (0);
}