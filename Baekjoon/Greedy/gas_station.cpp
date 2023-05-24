// Baekjoon
// 13305 주유소

#include <iostream>

int	km[100001];
int	cost[100001];

int main()
{
	int n;
	long long int	res(0), dist(0);
	
	// input
	std::cin >> n;
	for (int i=0;i<n-1;++i)
		std::cin >> km[i];
	for (int i=0;i<n;++i)
		std::cin >> cost[i];
	// solution
	for (int i=0;i<n-1;)
	{
		int cnt = 0;
		for (int j=i;j<n-1;++j)
		{
			if (cost[i] > cost[j])
				break;
			dist += km[j];
			cnt++;
		}
		res += dist * cost[i];
		dist = 0;
		i += cnt;
	}
	std::cout << res << std::endl;

	return (0);
}