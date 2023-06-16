// Baekjoon
// 1450 냅색문제

#include <iostream>
#include <algorithm>
#include <vector>

typedef	std::vector<long long>	vll;

int	n, c;
vll	arr;

vll	split_arr(int s, int len)
{
	vll	ret;
	// 포함되는 경우와 아닌 경우 전부 판단
	for (int i=0;i<(1 << len);++i) {
		long long	sum(0);
		for (int j=0;j<len;++j) {
			if (((1 << j) & i) != 0)
				sum += arr[s + j];
		}
		ret.push_back(sum);
	}
	return (ret);
}

int	main()
{
	// input
	std::cin >> n >> c;
	arr.assign(n, 0);
	for (int i=0;i<n;++i)
		std::cin >> arr[i];

	// solution
	int	res(0);
	vll	front = split_arr(0, n/2);
	vll	back;
	if (n % 2)
		back = split_arr(n/2, n/2 + 1);
	else
		back = split_arr(n/2, n/2);
	std::sort(back.begin(), back.end());
	for (long long a : front)
		res += std::upper_bound(back.begin(), back.end(), c - a) - back.begin();
	std::cout << res << '\n';

	return (0);
}