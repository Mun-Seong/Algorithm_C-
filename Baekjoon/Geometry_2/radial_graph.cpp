// Baekjoon
// 25308 방사형 그래프

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int		ans;
int		points[8];
double	temp[8];
bool	vis[8];

bool	check()
{
	for (int i=0;i<8;++i) {
		int	f = i, s = (i+1) % 8, t = (i+2) % 8;
		if (temp[f]*temp[t]*sqrt(2) >= temp[s]*(temp[f]+temp[t]))
			return (false);
	}
	return (true);
}

void	dfs(int c)
{
	if (c == 8 && check()) {
		ans++;
		return;
	}
	for (int i=0;i<8;++i) {
		if (vis[i])	continue;
		vis[i] = true;
		temp[c] = points[i];
		dfs(c+1);
		vis[i] = false;
	}
}

int	main()
{
	// input
	for (int i=0;i<8;++i)
		std::cin >> points[i];
	
	// solution - a1*a3*√2 >= a2*(a1+a3)
	dfs(0);
	std::cout << ans << '\n';
	
	return (0);
}