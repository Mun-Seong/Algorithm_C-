// Baekjoon
// 2156 포도주 시식

#include <iostream>

int wines[10001];
int	ans[10001];

int main()
{
	// input
	int	n;
	int res[2] = {0, 0};

	std::cin >> n;
	for(int i=1;i<=n;++i)
		std::cin >> wines[i];
	// solution
	ans[1] = wines[1];
	ans[2] = wines[2] + ans[1];
	for(int i=3;i<=n;++i)
	{
		// max (..OX, ..XO) + O
		ans[i] = std::max(ans[i-3] + wines[i-1], ans[i-2]) + wines[i];
		// i_th drink or not
		ans[i] = std::max(ans[i], ans[i-1]);
	}

	std::cout << ans[n] << std::endl;

	return (0);
}