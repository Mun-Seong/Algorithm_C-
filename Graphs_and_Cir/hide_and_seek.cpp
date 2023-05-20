// Baekjoon
// 1697 숨바꼭질

#include <iostream>
#include <algorithm>
#include <queue>

int		n, k, ans;
bool	vis[100000];

int	main()
{
	// input
	std::cin >> n >> k;

	// solution
	std::queue<std::pair<int, int>>	q;
	vis[n] = true;
	q.push({n, 0});
	while (!q.empty()) {
		int u = q.front().first;
		int	c = q.front().second;
		q.pop();

		if (u == k) {
			ans = c;
			break;
		}
		int arr[3] = {u-1, u+1, 2*u};
		for (int i=0;i<3;++i) {
			if (!(0 <= arr[i] && arr[i] <= 100000) || vis[arr[i]])
				continue;
			vis[arr[i]] = true;
			q.push({arr[i], c + 1});
		}
	}
	std::cout << ans << '\n';

	return (0);
}