// Baekjoon
// 1774 우주신과의 교감

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

typedef std::pair<long long int, long long int> pll;
typedef struct s_st
{
	/* data */
	long double	cost;
	int 	from;
	int 	to;
	/* finc */
	bool	operator < (const s_st &s2) const{ return (cost < s2.cost); }
} st;

int					n, m;
int					parent[1001];
pll					gods[1001];
std::vector<st>		ve;

long double	get_dist(pll a, pll b)
{
	long double	dx = (a.first - b.first) * (a.first - b.first);
	long double	dy = (a.second - b.second) * (a.second - b.second);

	return (sqrt(dx + dy));
}

int	find(int x)
{
	if (parent[x] == x)	return (x);
	else				return (parent[x] = find(parent[x]));
}

void	uf_union(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y) parent[y] = x;
}

bool	is_same_p(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return (true);
	return (false);
}



int	main()
{
	long double	ans(0);
	// input
	std::cin >> n >> m;
	for (int i=1;i<=n;++i) {
		std::cin >> gods[i].first >> gods[i].second;
		parent[i] = i;
	}
	for (int i=0;i<m;++i) {
		int from ,to;
		std::cin >> from >> to;
		uf_union(from, to);
	}

	// solution
	for (int i=1;i<=n;++i) {
		// cal dist all stars
		pll	from = gods[i];
		for (int j=i+1;j<=n;++j) {
			pll to = gods[j];
			long double	dist = get_dist(from, to);
			ve.push_back({dist, i, j});
		}
	}
	std::sort(ve.begin(), ve.end());

	for (int i=0;i<ve.size();++i) {
		if (is_same_p(ve[i].from, ve[i].to) == false) {
			uf_union(ve[i].from, ve[i].to);
			ans += ve[i].cost;
		}
	}
	std::cout << std::fixed;
	std::cout.precision(2);
	std::cout << ans << '\n';

	return (0);
}