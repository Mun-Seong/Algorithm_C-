// Baekjoon
// 2629 양팔저울

#include <iostream>
#include <cmath>

int	n, m;
int	w[31], b[8];	//weight, ball
int	dp[31][40000];

void	check_b(int i, int b)
{
	if (i > n || dp[i][b])
		return ;
	dp[i][b] = true;
	check_b(i + 1, b + w[i]);
	check_b(i + 1, abs(b - w[i]));
	check_b(i + 1, b);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	// input
	std::cin >> n;
	for (int i=0;i<n;++i)
		std::cin >> w[i];
	
	std::cin >> m;
	for (int i=0;i<m;++i)
		std::cin >> b[i];
	
	// solution
	check_b(0, 0);
	for (int i=0;i<m;++i) {
		if (b[i] > 15000)
			std::cout << "N ";
		else if (dp[n][b[i]])
			std::cout << "Y ";
		else
			std::cout << "N ";
	}

	return (0);
}