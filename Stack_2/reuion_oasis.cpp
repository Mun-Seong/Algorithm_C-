// Baekjoon
// 3015 오아시스 재결합

#include <iostream>
#include <stack>

int				n;
long long int	ans;
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
			ans += s.top().second;
			s.top().second++;
			if (s.size() != 1)
				ans++;
		}
		else {
			if (!s.empty())
				ans++;
			s.push({h[i], 1});
		}
	}
	std::cout << ans << '\n';
	return (0);
}