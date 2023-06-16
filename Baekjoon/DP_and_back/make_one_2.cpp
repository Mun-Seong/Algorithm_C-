// Baekjoon
// 12852 1로 만들기 2

#include <iostream>
#include <algorithm>
#include <cstring>

int	ans[3000001];
int	path[3000001];
int	n;

int	main()
{
	// input
	std::cin >> n;
	
	// solution
	int i = 1;
	ans[1] = 0;
	while (1) {
		if (ans[i+1] == 0)
			ans[i+1] = ans[i] + 1;
		else
			ans[i+1] = std::min(ans[i+1], ans[i]+1);
		if (ans[i+1] == ans[i]+1)
			path[i+1] = i;
		if (i + 1 >= n)
			break;
		if (ans[i*2] == 0)
			ans[i*2] = ans[i] + 1;
		else
			ans[i*2] = std::min(ans[i*2], ans[i]+1);
		if (ans[i*2] == ans[i]+1)
			path[i*2] = i;
		if (ans[i*3] == 0)
			ans[i*3] = ans[i] + 1;
		else
			ans[i*3] = std::min(ans[i*3], ans[i]+1);
		if (ans[i*3] == ans[i]+1)
			path[i*3] = i;
		++i;
	}
	std::cout << ans[n] << '\n';
	while (n != 0) {
		std::cout << n << ' ';
		n = path[n];
	}
	return (0);
}