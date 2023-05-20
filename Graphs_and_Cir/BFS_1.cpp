// Baekjoon
// 24444 알고리즘 수업-너비 우선 탐색 1

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

typedef std::vector<int> vec_i;

int		n, m, r, num(1);
vec_i	v[100001];
bool	vis[100001];
int		seq[100001];

void	bfs(int s)
{
	std::queue<int>	q;
	vis[s] = true;
	q.push(s);
	while (!q.empty()) {
		int	u = q.front();
		seq[u] = num++;
		q.pop();
		for (int a : v[u]) {
			if (!vis[a]) {
				vis[a] = true;
				q.push(a);
			}
		}
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
		std::sort(v[i].begin(), v[i].end());
	bfs(r);
	for (int i=1;i<=n;++i)
		std::cout << seq[i] << '\n';
	return (0);
}