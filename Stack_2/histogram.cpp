// Baekjoon
// 1725 히스토그램

#include <iostream>
#include <stack>
#include <algorithm>

int				n;
int				arr[100001];
std::stack<int>	s;


int	main()
{
	// input
	std::cin >> n;
	for (int i=0;i<n;++i)
		std::cin >> arr[i];

	// solution
	int ans(0);
	s.push(-1);
	for (int i=0;i<=n;++i) {
		while (!s.empty() && arr[s.top()] > arr[i]) {
			int idx = s.top();
			s.pop();
			ans = std::max(ans, arr[idx] * (i-s.top()-1));
		}
		s.push(i);
	}
	std::cout << ans << '\n';
	return (0);
}