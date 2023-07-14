// Baekjoon
// 2618 경찰차

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

typedef std::pair<int, int>	pii;

int	n, w;
pii	events[1003];
int	dp[1001][1001];
int	save[1001][1001];

int	get_dist(pii &car, pii &event)
{
	return (abs(car.first - event.first) + abs(car.second - event.second));
}

int	get_dp(int a, int b)
{
	if (a == w + 1 || b == w + 1)
		return (0);
	if (dp[a][b] != 0)
		return (dp[a][b]);
	
	int	next_case = std::max(a, b) + 1;

	int	dist_1 = get_dp(a, next_case) + get_dist(events[b], events[next_case]);
	int	dist_2 = get_dp(next_case, b) + get_dist(events[a], events[next_case]);

	if (dist_1 < dist_2)
		save[a][b] = 2;
	else
		save[a][b] = 1;
	
	dp[a][b] = std::min(dist_1, dist_2);
	
	return (dp[a][b]);
}

int	main()
{
	// input
	int	ew, sn;
	std::cin >> n >> w;
	events[0] = {1, 1};
	events[1] = {n, n};
	for (int i=2;i<w+2;++i)
		std::cin >> events[i].first >> events[i].second;

	// solution
	int a = 0, b = 1;
	std::cout << get_dp(a, b) << '\n';
	for (int i=2;i<w+2;++i) {
		int next_case = std::max(a, b) + 1;
		std::cout << save[a][b] << '\n';
		if (save[a][b] == 1)
			a = i;
		else
			b = i;
	}
	

	return (0);
}