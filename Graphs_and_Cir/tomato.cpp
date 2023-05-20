// Baekjoon
// 7576 토마토

#include <iostream>
#include <queue>
#include <vector>

typedef std::pair<int, int>	pii;

int		n, m, ans;
short	arr[1001][1001];

int	main()
{
	// input
	std::vector<pii>	v;		// save		1(entry point)
	std::vector<pii>	dv;		// save		next tomato pos
	int					cnt(0);	// count	0
	std::cin >> m >> n;
	for (int i=0;i<n;++i) {
		for (int j=0;j<m;++j) {
			std::cin >> arr[i][j];
			if (arr[i][j] == 1)
				v.push_back({i, j});
			if (arr[i][j] == 0)
				cnt++;
		}
	}

	// solution
	std::queue<std::vector<pii>>	q;
	q.push(v);
	while (!q.empty()) {
		if (cnt == 0)
			break ;
		std::vector<pii>	u = q.front();
		dv.clear();
		q.pop();
		for (pii i : u) {
			int	d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
			for (int j=0;j<4;++j) {
				int	dx = i.first + d[j][0];
				int	dy = i.second + d[j][1];

				if (arr[dx][dy] != 0 || !(0 <= dx && dx < n) 
					|| !(0 <= dy && dy < m))
					continue;
				arr[dx][dy] = 1;
				cnt--;
				dv.push_back({dx, dy});
			}
		}
		if (!dv.empty())
			q.push(dv);
		ans++;
	}
	if (cnt != 0)	std::cout << "-1" << '\n';	
	else			std::cout << ans << '\n';

	return (0);
}
