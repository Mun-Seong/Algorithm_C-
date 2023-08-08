// Baekjoon
// 1197 최소 스패닝 트리

#include <iostream>
#include <algorithm>
#include <vector>

typedef struct s_st
{
	/* data */
	int cost;
	int from;
	int to;
	/* finc */
	bool	operator < (const s_st &s2) const{ return (cost < s2.cost); }
} st;

int					v, e;
int					parent[10001];
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
	int	ans(0);
	std::cin >> v >> e;
	for (int i=0;i<e;++i) {
		st	tmp;
		std::cin >> tmp.from >> tmp.to >> tmp.cost;
		ve.push_back(tmp);
	}

	// solution
	std::sort(ve.begin(), ve.end());
	for (int i=1;i<=v;++i)
		parent[i] = i;
	for (int i=0;i<e;++i) {
		if (is_same_p(ve[i].from, ve[i].to) == false)
		{
			uf_union(ve[i].from, ve[i].to);
			ans += ve[i].cost;
		}
	}
	std::cout << ans << '\n';

	return (0);
}