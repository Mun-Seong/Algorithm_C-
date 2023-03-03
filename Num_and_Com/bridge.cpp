// Baekjoon
// 1010 다리 놓기

#include <iostream>
#include <vector>

int main()
{
	int T;
	std::vector<int> ans;
	std::cin >> T;

	std::pair<int, int> p[T];
	for (int i=0;i<T;++i)
		std::cin >> p[i].first >> p[i].second;

	// solution
	for (int i=0;i<T;++i)
	{
		int N = p[i].second;
		int pascal_arr[N+1][N+1];
		for (int i=0;i<=N;++i)
			pascal_arr[i][0] = 1;
		for (int i=1;i<=N;i++)
		{
			for (int j=1;j<=i;j++)
			{
				if (j == i)
				{
					pascal_arr[i][j] = 1;
				}
				else
				{
					pascal_arr[i][j] = pascal_arr[i-1][j-1] + pascal_arr[i-1][j];
				}
			}
		}
		ans.push_back(pascal_arr[N][p[i].first]);
	}
	for (int i : ans)
		std::cout << i << '\n';
}