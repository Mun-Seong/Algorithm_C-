// Baekjoon
// 9251 LCS

#include <iostream>
#include <string>

int ans[1001][1001];

int main()
{
	// input
	std::string	a, b;
	std::cin >> a >> b;
	// solution
	for (int i=1;i<=a.length();++i)
	{
		for (int j=1;j<=b.length();++j)
		{
			if (a[i-1] == b[j-1])
				ans[i][j] = ans[i-1][j-1] + 1;
			else
				ans[i][j] = std::max(ans[i-1][j], ans[i][j-1]);
		}
	}
	std::cout << ans[a.length()][b.length()] << std::endl;
}