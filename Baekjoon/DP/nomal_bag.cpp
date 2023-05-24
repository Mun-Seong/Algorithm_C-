// Baekjoon
// 12865 평범한 배낭

#include <iostream>

int w[101], v[101];
int ans[101][100001];

int main()
{
	// input
	int n, k;

	std::cin >> n >> k;
	for (int i=1;i<=n;++i)
		std::cin >> w[i] >> v[i];
	// solution
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=k;++j)
		{
			if (j - w[i] >= 0)
				ans[i][j] = std::max(ans[i-1][j], ans[i-1][j-w[i]] + v[i]);
			else
				ans[i][j] = ans[i-1][j];
		}
	}
	std::cout << ans[n][k] << std::endl;
}