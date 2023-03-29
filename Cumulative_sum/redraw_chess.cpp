// Baekjoon
// 25682 체스판 다시 칠하기 2

#include <iostream>

int	sum_w[2001][2001];
int	sum_b[2001][2001];

int main()
{
	// input
	std::ios_base::sync_with_stdio(false); 
	std::cout.tie(NULL); 
	std::cin.tie(NULL);


	int n, m, k;
	std::cin >> n >> m >> k;
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<m;++j)
			std::cin >> board[i][j];
	}
}