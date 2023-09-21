// Baekjoon
// 17472 다리 만들기 2

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

typedef std::pair<int, int> pii;
typedef struct s_st
{
	/* data */
	int		cost;
	int 	from;
	int 	to;
	/* finc */
	bool	operator < (const s_st &s2) const{ return (cost < s2.cost); }
} st;

int					n, m;
int					parent[200000];
std::vector<st>		ve;

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
	while (true) {
		std::cin >> m >> n;
		if (m == 0 && n == 0)
			break ;
		// init
		for (int i=0;i<m;++i)	parent[i] = i;
		ve.clear();
		int	sum_dist(0), shortest_dist(0);
		// input
		for (int i=0;i<n;++i) {
			int	from, to, cost;
			std::cin >> from >> to >> cost;
			sum_dist += cost;
			ve.push_back({cost, from, to});
		}
		// solution
		std::sort(ve.begin(), ve.end());

		for (int i=0;i<ve.size();++i) {
			if (is_same_p(ve[i].from, ve[i].to) == false) {
				uf_union(ve[i].from, ve[i].to);
				shortest_dist += ve[i].cost;
			}
		}
		
		std::cout << sum_dist - shortest_dist << '\n';
	}

	return (0);
}