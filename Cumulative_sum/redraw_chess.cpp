// Baekjoon
// 25682 체스판 다시 칠하기 2

#include <iostream>
#include <string>

int			sum_w[2001][2001];
int			sum_b[2001][2001];

int main()
{
	// input
	std::ios_base::sync_with_stdio(false); 
	std::cout.tie(NULL); 
	std::cin.tie(NULL);


	int n, m, k;
	std::cin >> n >> m >> k;
	k--;
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<m;++j)
		{
			char	c;
			std::cin >> c;
			if ((i + j) % 2)
			{
				
				if (c == 'W')
				{
					// start B
					sum_b[i][j+1] = sum_b[i][j];
					// start W
					sum_w[i][j+1] = sum_w[i][j] + 1;
				}
				else
				{
					sum_b[i][j+1] = sum_b[i][j] + 1;
					sum_w[i][j+1] = sum_w[i][j];
				}
			}
			else
			{
				if (c == 'W')
				{
					// start B
					sum_b[i][j+1] = sum_b[i][j] + 1;
					// start W
					sum_w[i][j+1] = sum_w[i][j];
				}
				else
				{
					sum_b[i][j+1] = sum_b[i][j];
					sum_w[i][j+1] = sum_w[i][j] + 1;
				}
			}
		}
	}
	int min_b(9999), min_w(9999);
	for (int j=1;j+k<=m;++j)
	{
		for (int i=0;i+k<n;++i)
		{
			int ans_b(0), ans_w(0);
			for (int ii=0;ii<=k;++ii)
			{
				ans_b += sum_b[i+ii][j+k] - sum_b[i+ii][j-1];
				ans_w += sum_w[i+ii][j+k] - sum_w[i+ii][j-1];
			}
			min_b = std::min(min_b, ans_b);
			min_w = std::min(min_w, ans_w);
		}
	}
	std::cout << std::min(min_b, min_w) << '\n';
}