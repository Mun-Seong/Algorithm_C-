// Baekjoon
// 1300 K번째 수

#include <iostream>
#include <algorithm>

int n, k;

int main()
{
	// input
	int	res(0);
	std::cin >> n >> k;
	
	// solution
	int start, end, mid;
	start = 1;
	end = k;

	while (start <= end)
	{
		mid = (start + end) / 2;
		int num = 0;
		for (int i=1;i<=n;++i)
			num += std::min(n, mid / i);
		if (num >= k)
		{
			res = mid;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	std::cout << res << '\n';

	return (0);
}