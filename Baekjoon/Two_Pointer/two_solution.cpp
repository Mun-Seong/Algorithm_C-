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
	int	i(0), j(n-1), ii(i), jj(j);
	std::sort(arr, arr+n);
	ans = arr[i] + arr[j];
	while (i < j) {
		sum = arr[i] + arr[j];
		if (abs(ans) > abs(sum)) {
			ans = sum;
			ii = i;
			jj = j;
		}
		if (sum == 0)
			break ;
		if (abs(arr[i]) > abs(arr[j]))
			i++;
		else
			j--;
	}
	std::cout << arr[ii] << ' ' << arr[jj] << '\n';
	return (0);
}
