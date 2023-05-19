// Baekjoon
// 3015 오아시스 재결합

#include <iostream>
#include <stack>

int				n, ans;
int				h[500000];
std::stack<std::pair<int,int>>	s;


int	main()
{
	// input
	std::cin >> n;
	for (int i=0;i<n;++i)
		std::cin >> h[i];
	
	// solution
	for (int i=0;i<n;++i) {
		while (!s.empty() && s.top().first < h[i]) {
			ans += s.top().second;
			s.pop();
		}
		if (!s.empty() && h[i] == s.top().first) {
			ans += s.top().second + 1;
			auto tmp = s.top();
			s.pop();
			tmp.second++;
			s.push(tmp);
		}
		else
			s.push({h[i], 1});
	}
	std::cout << ans << '\n';

	return (0);
}