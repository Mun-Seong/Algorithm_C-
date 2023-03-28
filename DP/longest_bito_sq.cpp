// Baekjoon
// 11054 가장 긴 바이토닉 부분 수열

#include <iostream>

int a[1001];
int ans[1001][2];

int main()
{
	// input
	int n;
	int res(0);
	std::cin >> n;
	for (int i=1;i<=n;++i)
		std::cin >> a[i];
	// solution
	for (int i=1;i<=n;++i)
	{
		ans[i][0] = 1;
		for (int j=1;j<i;++j)
		{
			if (a[i] > a[j])
				ans[i][0] = std::max(ans[i][0], ans[j][0] + 1);
		}
	}
	for (int i=n;i>=1;--i)
	{
		ans[i][1] = 1;
		for (int j=n;j>i;--j)
		{
			if (a[i] > a[j])
				ans[i][1] = std::max(ans[i][1], ans[j][1] + 1);
		}
	}
	for (int i=1;i<=n;++i)
		//std::cout << ans[i][0] << ' ' << ans[i][1] << std::endl;
		res = std::max(res, ans[i][0] + ans[i][1] - 1);	
	std::cout << res << std::endl;
}