// Baekjoon
// 2579	계단 오르기

#include <iostream>

int stairs[301];
int	ans[301][2];

int main()
{
	// input
	int	n;
	int res(0);

	std::cin >> n;
	for(int i=1;i<=n;++i)
		std::cin >> stairs[i];
	// solution
	ans[1][1] = stairs[1];

	for(int i=2;i<=n;++i)
	{
		// [x][0] = prev , [x][1] = prev of prev
		ans[i][0] = ans[i-1][1] + stairs[i];
		ans[i][1] = std::max(ans[i-2][0], ans[i-2][1]) + stairs[i];
	}
	res = std::max(ans[n][0], ans[n][1]);
	std::cout << res << std::endl;

	return (0);
}