// Baekjoon
// 1932 정수 삼각형

#include <iostream>

int tri[501][501];

int main()
{
	int n;
	long long ans(0);

	std::cin >> n;
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<i+1;++j)
			std::cin >> tri[i][j];
	}
	ans = tri[0][0];
	int j = 0;
	for (int i=1;i<n;++i)
	{
		if (tri[i][j] >= tri[i][j+1])
		{
			ans += tri[i][j];
		}
		else
		{
			ans += tri[i][j+1];
			j++;
		}
	}
	std::cout << ans << std::endl;
}