// Baekjoon
// 2565 전깃줄

#include <iostream>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> pii;

int	ans[101];

bool	cmp(pii a, pii b)
{
	if (a.first < b.first)
		return (true);
	return (false);
}

int	main()
{
	// input
	std::vector<std::pair<int, int> > ab;
	int	n;
	int	res(0);
	std::cin >> n;
	for(int i=0;i<n;++i)
	{
		int f, s;
		std::cin >> f >> s;
		ab.push_back(std::make_pair(f, s));
	}

	// solution
	std::sort(ab.begin(), ab.end(), cmp);

	for (int i=1;i<=n;++i)
		ans[i] = 1;
	for (int i=2; i<=n; ++i)
	{
		for (int j=1;j<i;++j)
		{
			if (ab[i-1].second > ab[j-1].second)
				ans[i] = std::max(ans[i], ans[j] + 1);
		}
	}
	for (int i=1;i<=n;++i)
		res= std::max(res, ans[i]);
	std::cout << n - res << std::endl;
}