// Baekjoon
// 3273 두 수의 합

#include <iostream>
#include <algorithm>

int	n, x;
int	arr[100000];

int	main()
{
	// input
	std::cin >> n;
	for (int i=0;i<n;++i) {
		std::cin >> arr[i];
	}
	std::cin >> x;
	
	// solution
	int	ans(0), sum;
	int	i(0), j(n-1);
	std::sort(arr, arr+n);
	while (i < j) {
		sum = arr[i] + arr[j];
		if (sum == x) {
			ans++;
			i++;
			j--;
		}
		else if (sum < x)
			i++;
		else
			j--;
	}
	std::cout << ans << '\n';

	return (0);
}