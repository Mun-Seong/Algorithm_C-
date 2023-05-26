// Baekjoon
// 1707 이분 그래프

// mem over and sol to use vector container

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

std::vector<int> 				c;
std::vector<std::vector<int>>	g;

int	main()
{
	// input
	int	k;
	std::cin >> k;
	for (int t=0;t<k;++t) {
		int		v, e;
		bool	ans(true);
		std::cin >> v >> e;
		g.assign(v+1, std::vector<int>(0,0));
		c.assign(v+1, 0);
		for (int i=0;i<e;++i) {
			int	f, s;
			std::cin >> f >> s;
			g[f].emplace_back(s);
			g[s].emplace_back(f);
		}

		// solution
		for (int i=1;i<=v;++i) {
			if (!ans)
				break;
			if (c[i] == 0) {
				std::queue<int>	q;
				q.push(i);
				c[i] = -1;
				while (!q.empty() && ans) {
					int	u = q.front();	q.pop();
					for (int j : g[u]) {
						if (c[j] == 0) {
							q.push(j);
							c[j] = c[u] * -1;
						}
						else if (c[u] + c[j] != 0) {
							ans = false;
							break;
						}
					}
				}
			}
		}
		if (ans)
			std::cout << "YES";
		else
			std::cout << "NO";
		std::cout << std::endl;
	}
	return (0);
}
