// Baekjoon
// 24480 알고리즘 수업-깊이 우선 탐색 2

#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int> vec_i;

int		n, m, r, num(1);
vec_i	v[100001];
bool	vis[100001];
int		seq[100001];

void	dfs(int s)
{
	vis[s] = true;
	seq[s] = num++;
	for (int i : v[s]) {
		if (!vis[i])
			dfs(i);
	}
}

int	main()
{
	// input
	std::cin >> n >> m >> r;
	for (int i=0;i<m;++i) {
		int	s, e;
		std::cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}

	// solution
	for (int i=1;i<=n;++i)
		std::sort(v[i].begin(), v[i].end(), std::greater<int>());
	dfs(r);
	for (int i=1;i<=n;++i)
		std::cout << seq[i] << '\n';
	return (0);
}