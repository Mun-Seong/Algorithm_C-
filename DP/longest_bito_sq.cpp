// Baekjoon
// 11054 가장 긴 바이토닉 부분 수열

#include <iostream>

int a[1001];
int ans[1001];

int main()
{
	// input
	int n;
	std::cin >> n;
	for (int i=1;i<=n;++i)
		std::cin >> a[i];
	// solution
	for (int i=1;i<=n;++i)
		ans[i] = 1;
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<i;++j)
		{
			if (a[i] < a[j])
				ans[i] = std::max(ans[i], ans[j] + 1);
		}
		for (int j=i;j<=n;++j)
		{
			if (a[i] > a[j])
				ans[i] = std::max(ans[i], ans[j] + 1);
		}
	}
	for (int i=1;i<=n;++i)
		std::cout << ans[i] << ' ';
	std::cout << std::endl;
}