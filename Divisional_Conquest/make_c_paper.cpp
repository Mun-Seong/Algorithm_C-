// Baekjoon
// 2630 색종이 만들기

#include <iostream>

int	input[128][128];
int	b, w, n;

bool	is_not_same(int s, int e, int gap)
{
	bool color = input[s][e];
	for (int i=s;i<s+gap;++i)
	{
		for (int j=e;j<e+gap;++j)
		{
			if (color != input[i][j])
				return(true);
		}
	}
	if (color)
		b++;
	else
		w++;
	return (false);
}

void	split_board(int x, int y, int gap)
{
	if (is_not_same(x, y, gap))
		split_board(x, y, gap / 2);
	if (gap == n)
		return ;
	if (is_not_same(x + gap, y, gap))
		split_board(x + gap, y, gap / 2);
	if (is_not_same(x, y + gap, gap))
		split_board(x, y + gap, gap / 2);
	if (is_not_same(x + gap, y + gap, gap))
		split_board(x + gap, y + gap, gap / 2);
}


int main()
{
	// input
	std::cin >> n;
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<n;++j)
			std::cin >> input[i][j];
	}

	// solution
	split_board(0, 0, n);
	std::cout << w << '\n' << b << std::endl;

	return (0);
}