// Baekjoon
// 11660 구간 합 구하기 5

#include <iostream>

int	sum[1025][1025];

int main()
{
	// input
	std::ios_base::sync_with_stdio(false); 
	std::cout.tie(NULL); 
	std::cin.tie(NULL);

	int n, m, num;
	
	std::cin >> n >> m;
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=n;++j)
		{
			std::cin >> num;
			sum[i][j] = sum[i][j-1] + num;
		}
	}
	for (int i=0;i<m;++i)
	{
		int x1, y1, x2, y2, ans(0);
		std::cin >> x1 >> y1 >> x2 >> y2;
		for (int j=x1;j<=x2;++j)
			ans += sum[j][y2] - sum[j][y1-1];
		std::cout << ans << '\n';
	}
	return (0);
}
