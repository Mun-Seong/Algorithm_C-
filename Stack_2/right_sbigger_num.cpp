// Baekjoon
// 17299 오등큰수

#include <iostream>
#include <stack>

int				n;
int				arr[1000000];
int				cnt[1000001];
int				ans[1000000];
std::stack<int>	s;

int	main()
{
	// input
	std::cin >> n;
	int	tmp;
	for (int i=0;i<n;++i) {
		std::cin >> arr[i];
		cnt[arr[i]]++;
	}

	// solution
	for (int i=n-1;i>=0;--i) {
		while (!s.empty() && cnt[s.top()] <= cnt[arr[i]])
			s.pop();
		if (s.empty())	ans[i] = -1;
		else			ans[i] = s.top();
		s.push(arr[i]);
	}

	for (int i=0;i<n;++i)
		std::cout << ans[i] << ' ';
	
	return (0);
}