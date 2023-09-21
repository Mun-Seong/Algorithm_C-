// Baekjoon
// 4386 별자리 만들기

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

typedef	std::pair<double, double>	pdd;

typedef struct s_st
{
	/* data */
	double	cost;
	int 	from;
	int 	to;
	/* finc */
	bool	operator < (const s_st &s2) const{ return (cost < s2.cost); }
} st;

int				n;
int				parent[100];
pdd				stars[100];
std::vector<st>	ve;


double	get_dist(pdd a, pdd b)
{
	double	dx = (a.first - b.first) * (a.first - b.first);
	double	dy = (a.second - b.second) * (a.second - b.second);

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
	// input
	double	ans(0);
	std::cin >> n;
	for (int i=0;i<n;++i)
		std::cin >> stars[i].first >> stars[i].second; 
	
	// solution
	for (int i=0;i<n;++i) {
		// init parent
		parent[i] = i;
		// cal dist all stars
		pdd	from = stars[i];
		for (int j=i+1;j<n;++j) {
			pdd to = stars[j];
			double	dist = get_dist(from, to);
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

    std::cout.precision(3);
	std::cout << ans << '\n';
	
	return (0);
}