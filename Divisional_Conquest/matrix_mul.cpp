// Baekjoon
// 2740 행렬 곱셈

#include <iostream>

int	mat1[100][100], mat2[100][100], ans[100][100];
int n, m, k;

int	each_val(int i, int j)
{
	int ret(0);
	for (int a=0;a<m;++a)
	{
		ret += mat1[i][a] * mat2[a][j];
	}
	return (ret);
}

void	matrix_mul()
{
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<k;++j)
		{
			ans[i][j] = each_val(i, j);
		}
	}
}

int main()
{
	// input
	std::cin >> n >> m;
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<m;++j)
			std::cin >> mat1[i][j];
	}
	std::cin >> m >> k;
	for (int i=0;i<m;++i)
	{
		for (int j=0;j<k;++j)
			std::cin >> mat2[i][j];
	}

	// solution
	matrix_mul();
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<k;++j)
			std::cout << ans[i][j] << ' ';
		std::cout << "\n";
	}
	return (0);
}