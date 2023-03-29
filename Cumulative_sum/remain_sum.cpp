// Baekjoon
// 10986 나머지 합

#include <iostream>

long long	cnt[1001];
long long	sum, ans;

int main()
{
	// input
	std::ios_base::sync_with_stdio(false); 
	std::cout.tie(NULL); 
	std::cin.tie(NULL);

	int	n, m, num;
	std::cin >> n >> m;
	for (int i=0;i<n;++i)
	{
		std::cin >> num;
		sum += num;
		cnt[sum % m]++;
	}
	for (int i=0;i<1001;++i)
		ans += cnt[i] * (cnt[i] - 1) / 2;
	std::cout << ans + cnt[0];
}