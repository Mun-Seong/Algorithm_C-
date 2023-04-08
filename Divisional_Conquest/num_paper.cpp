// Baekjoon
// 1780 종이의 개수

#include <iostream>

int n;
int	arr[2200][2200];
int	o, z, m;

bool	is_not_same(int x, int y, int gap)
{
	int	t = arr[x][y];
	for (int i=x;i<x+gap;++i)
	{
		for (int j=y;j<y+gap;++j)
		{
			if (arr[i][j] != t)
				return (true);
		}
	}
	if (t == 0)	z++;
	else if (t == 1)	o++;
	else if (t == -1)	m++;
	return (false);
}


void	split_arr(int x, int y, int gap)
{
	for (int i=0;i<3;++i)
	{
		for (int j=0;j<3;++j)
		{
			if (is_not_same(x + (gap * i), y + (gap * j), gap))
				split_arr(x + (gap * i), y + (gap * j), gap / 3);
			if (gap == n)
				return ;
		}
	}
}

int main()
{
	// input
	std::cin >> n;
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<n;++j)
			std::cin >> arr[i][j];
	}

	// solution
	split_arr(0, 0, n);
	std::cout << m << '\n' << z << '\n' << o << '\n';
	return (0);
}