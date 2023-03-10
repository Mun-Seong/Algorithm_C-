// Baekjoon
// 14889 스타트와 링크

//nCn/2의 반 만큼의 경우의 수 발생
#include <iostream>
#include <cmath>
//#include <algorithm>

int 	N, ans(999999999);
int 	s[20][20];
bool	check[20];

void	solution(int cnt, int pos)
{
	if (cnt == N/2)
	{
		int start(0), link(0);
		for (int i=0;i<N;++i)
		{
			for (int j=0;j<N;++j)
			{
				if (check[i] == check[j])
				{
					if (check[i])
						start += s[i][j];
					else
						link += s[i][j];
				}
			}
		}
		ans = std::min(ans, abs(start - link));
		return;
	}
	for (int i=pos;i<N;++i)
	{
		check[i] = true;
		solution(cnt+1, i+1);
		check[i] = false;		 
	}
}

int main()
{
	std::cin >> N;
	for (int i=0;i<N;++i)
	{
		for (int j=0;j<N;++j)
			std::cin >> s[i][j];
	}
	solution(0, 0);
	std::cout << ans << '\n';
}