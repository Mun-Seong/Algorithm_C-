// Baekjoon
// 1992 쿼드트리

#include <iostream>
#include <string>

int n;
std::string	s[64];

bool	is_not_same(int x, int y, int gap)
{
	char	c = s[x][y];
	for (int i=x;i<x+gap;++i)
	{
		for (int j=y;j<y+gap;++j)
		{
			if (s[i][j] != c)
				return (true);
		}
	}
	std::cout << c;
	return (false);
}

void	split_s(int x, int y, int gap)
{
	if (gap != n)
		std::cout << '(';
	if (is_not_same(x, y, gap))
		split_s(x, y, gap / 2);
	if (gap == n)
		return ;
	if (is_not_same(x, y + gap, gap))
		split_s(x, y + gap, gap / 2);
	if (is_not_same(x + gap, y, gap))
		split_s(x + gap, y, gap / 2);
	if (is_not_same(x + gap, y + gap, gap))
		split_s(x + gap, y + gap, gap / 2);
	std::cout << ')';
}

int main()
{
	// input
	std::cin >> n;
	for (int i=0;i<n;++i)
	{
		std::cin >> s[i];
	}

	// solution
	split_s(0, 0, n);
}