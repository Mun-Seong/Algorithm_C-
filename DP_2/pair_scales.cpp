// Baekjoon
// 2629 양팔저울

#include <iostream>

int	n, m;
int	w[31], b[8];	//weight, ball
int	dp[40000];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	// input
	std::cin >> n;
	for (int i=1;i<=n;++i)
		std::cin >> w[i];
	
	std::cin >> m;
	for (int i=1;i<=m;++i)
		std::cin >> b[i];
	
	// solution


	return (0);
}