// Baekjoon
// 16928 뱀과 사다리 게임

#include <iostream>
#include <queue>

typedef std::pair<int, int>	pii;

int		n, m, ans(2000000);
short	gimmick[101];
bool	vis[101];

int	main()
{
	// input
	std::cin >> n >> m;
	for (int i=0;i<n+m;++i) {
		int	s, e;
		std::cin >> s >> e;
		gimmick[s] = e;
	}
	
	// solution
	std::queue<pii>	q;
	q.push({1, 0});

	while (!q.empty()) {
		pii	u = q.front();
		q.pop();
		if (u.first == 100) {
			ans = u.second;
			break;
		}
		for (int i=1;i<7;++i) {
			int next = u.first + i;
			if (next > 100 || vis[next]) continue;
			if (gimmick[next])
				next = gimmick[next];
			q.push({next, u.second + 1});
			vis[next] = true;
		}
	}
	std::cout << ans << '\n';

	return (0);
}