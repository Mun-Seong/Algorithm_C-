// Baekjoon
// 1305 광고

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int			l;
std::string	s;

std::vector<int>	lps(std::string p)
{
	int	m = p.length();
	std::vector<int>	part(m, 0);

	for (int i=1,j=0;i<m;++i) {
		while (j > 0 && p[i] != p[j])
			j = part[j - 1];
		if (p[i] == p[j])
			part[i] = ++j;
	}

	return (part);
}

int	main()
{
	// input
	std::cin >> l >> s;

	// solution	-
	std::vector<int>	part = lps(s);
	std::cout << l - part[l - 1] << '\n';

	return (0);
}