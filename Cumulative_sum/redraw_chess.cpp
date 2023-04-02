// Baekjoon
// 25682 체스판 다시 칠하기 2

#include <iostream>
#include <string>

int			sum_b[2001][2001];
char		board[2001][2001];
int			n, m, k;

int	each_min(char c)
{
	int tmp, cnt(INT32_MAX);
	for(int i=0;i<n;++i)
	{
		for (int j=0;j<m;++j)
		{
			if ((i + j) % 2)
				tmp = board[i][j] == c;
			else
				tmp = board[i][j] != c;
			sum_b[i+1][j+1] = sum_b[i][j+1] + sum_b[i+1][j]
				- sum_b[i][j] + tmp;
		}
	}
	for (int i=1;i<=n-k+1;++i)
	{
		for (int j=1;j<=m-k+1;++j)
			cnt = std::min(cnt, sum_b[i+k-1][j+k-1]
				- sum_b[i+k-1][j-1] - sum_b[i-1][j+k-1]
				+ sum_b[i-1][j-1]);
	}
	return (cnt);
}

int main()
{
	// input
	std::ios_base::sync_with_stdio(false); 
	std::cout.tie(NULL); 
	std::cin.tie(NULL);

	std::cin >> n >> m >> k;
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<m;++j)
			std::cin >> board[i][j];
	}
	std::cout << std::min(each_min('B'), each_min('W')) << '\n';
}