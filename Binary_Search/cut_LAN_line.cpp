// Baekjoon
// 1654 랜선 자르기

#include <iostream>

int	k, n;
int	have[10000];

typedef unsigned long long ull;

int main()
{
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	// input
	ull	sum = 0;
	int	num = 0;
	std::cin >> k >> n;
	for (int i=0;i<k;++i) {
		std::cin >> have[i];
		sum += have[i];
	}
	
	// solution
	ull	max_len = sum / n, min_len = 1, mid;
	for (int i=0;i<k;++i)
		num += have[i] / max_len;
	if (num >= n)
	{
		// max_len이 정답이 되는 경우
		std::cout << max_len << '\n';
		return 0;
	}
	// max_len이 정답이 아닌 경우 (1 ~ max_len) 탐색
	while (min_len <= max_len)
	{
		num = 0;
		mid = (max_len + min_len) / 2;
		for (int i=0;i<k;++i)
		{
			if (num >= n)
				break ;
			num += have[i] / mid;
		}
		if (num >= n)
			min_len = mid + 1;
		else
			max_len = mid - 1;
	}
	std::cout << mid << '\n';

}