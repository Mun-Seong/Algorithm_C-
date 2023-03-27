// Baekjoon
// 11053 가장 긴 증가하는 부분 수열

#include <iostream>

int	arr[1001];
int ans[1001];

int main()
{
	// input
	int	n;
	int res(0);
	std::cin >> n;
	for (int i=1; i<=n; ++i)
		std::cin >> arr[i];
	// solution
	for (int i=1;i<=n;++i)
		ans[i] = 1;
	for (int i=2; i<=n; ++i)
	{
		for (int j=1;j<i;++j)
		{
			if (arr[i] > arr[j])
				ans[i] = std::max(ans[i], ans[j] + 1);
		}
	}
	for (int i=1;i<=n;++i)
		res= std::max(res, ans[i]);
	std::cout << res << std::endl;
}