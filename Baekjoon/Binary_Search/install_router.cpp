// Baekjoon
// 2110 공유기 설치

#include <iostream>
#include <algorithm>

int n, c;
int	pos[200000];

int main()
{
	// input
	int	res = 0;
	std::cin >> n >> c;
	for (int i=0;i<n;++i)
		std::cin >> pos[i];
	
	// solution
	std::sort(pos, pos + n);
	int	start, mid, end, num, tmp_pos;
	start = 1;
	end = pos[n-1] - pos[0];
	while (start <= end)
	{
		num = 1;
		mid = (start + end) / 2;
		tmp_pos = pos[0];

		for (int i=1;i<n;++i)
		{

			if (pos[i] - tmp_pos >= mid)
			{
				num++;
				tmp_pos = pos[i];
			}
		}
		if (num >= c)
		{
			res = std::max(res, mid);
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	std::cout << res << '\n';
	return (0);
}
