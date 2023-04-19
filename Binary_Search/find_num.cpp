// Baekjoon
// 1920 수 찾기

#include <iostream>
#include <algorithm>

int	a[100000];
int	n, m;

bool	binary_search(int i, int s, int e)
{
	while (s <= e)
	{
		int mid = (s+e) / 2;

		if (i == a[mid])
			return 1;
		else if (i < a[mid])
			e = mid - 1;
		else
			s = mid + 1;
	}
	return 0;
}

int main()
{
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	// input
	int	tmp;
	std::cin >> n;
	for (int i=0;i<n;++i)
		std::cin >> a[i];
	std::sort(a, a+n);
	std::cin >> m;
	for (int i=0;i<m;++i)
	{
		std::cin >> tmp;
		std::cout << binary_search(tmp, 0, n-1) << '\n';
	}
}