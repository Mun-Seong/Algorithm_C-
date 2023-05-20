// Baekjoon
// 7569 토마토

#include <iostream>
#include <queue>
#include <vector>

typedef std::pair<int, std::pair<int, int>>	piii;
//	{h, {y, x}};

int		n, m, h, ans;
short	arr[101][101][101];

int	main()
{
	// input
	std::vector<piii>	v;		// save		1(entry point)
	std::vector<piii>	dv;		// save		next tomato pos
	int					cnt(0);	// count	0
	std::cin >> m >> n >> h;

	for (int i=0;i<h;++i) {
		for (int j=0;j<n;++j) {
			for (int k=0;k<m;++k) {
				std::cin >> arr[i][j][k];
				if (arr[i][j][k] == 1)
					v.push_back({i, {j, k}});
				if (arr[i][j][k] == 0)
					cnt++;
			}
		}
	}

	// solution
	std::queue<std::vector<piii>>	q;
	q.push(v);
	while (!q.empty()) {
		if (cnt == 0)
			break ;
		std::vector<piii>	u = q.front();
		dv.clear();
		q.pop();
		for (piii i : u) {
			int	d[6][3] = {	{1,0,0}, {-1,0,0},
							{0,1,0}, {0,-1,0},
							{0,0,1}, {0,0,-1}};
			for (int j=0;j<6;++j) {
				int	dh = i.first + d[j][0];
				int	dx = i.second.first + d[j][1];
				int	dy = i.second.second + d[j][2];

				if (arr[dh][dx][dy] != 0 || !(0 <= dx && dx < n) 
					|| !(0 <= dy && dy < m) || !(0 <= dh && dh < h))
					continue;
				arr[dh][dx][dy] = 1;
				cnt--;
				dv.push_back({dh, {dx, dy}});
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
