// Baekjoon
// 2470 두 용액

#include <iostream>
#include <cmath>
#include <algorithm>

int	n;
int	arr[100001];

int	main()
{
	// input
	std::cin >> n;
	for (int i=0;i<n;++i) {
		std::cin >> arr[i];
	}

	// solution
	long long	sum, ans;
	int	i(0), j(n-1), ii, jj;
	ans = arr[i] + arr[j];
	std::sort(arr, arr+n);
	while (i < j) {
		sum = arr[i] + arr[j];
		if (sum == 0)
			break ;
		if (abs(ans) > abs(sum)) {
			ans = sum;
			ii = i;
			jj = j;
		}
		else if (abs(arr[i]) < abs(arr[j]))
			i++;
		else
			j--;
	}
	std::cout << ans << '\n';
	return (0);
}
