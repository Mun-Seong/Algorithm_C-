// Baekjoon
// 1786 찾기

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

std::string			t, p;
std::vector<int>	k, ans;

std::vector<int>	make_k(std::string p)
{
	int m = p.length();
	std::vector<int>	tk(m, 0);
	
	for (int i=1, j=0;i<m;++i) {
		while (j > 0 && p[i] != p[j])
			j = tk[j-1];
		if (p[i] == p[j])
			tk[i] = ++j;
	}
	return (tk);
}

int	main()
{
	// input
	std::getline(std::cin, t);
	std::getline(std::cin, p);

	// solution
	int	n = t.length(), m = p.length();
	int	i = 0, j = 0;
	k = make_k(p);

	while (i <= n - m) {
		if (t[i + j] == p[j]) {
			++j;
			if (j == m)	ans.push_back(i+1);
		}
		else {
			if (j == 0)
				++i;
			else {
				i += j - k[j - 1];
				j = k[j - 1];
			}
		}
	}
	std::cout << ans.size() << '\n';
	for (auto a : ans)
		std::cout << a << ' ';
	std::cout << '\n';

	return (0);
}