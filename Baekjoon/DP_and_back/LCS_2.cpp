// Baekjoon
// 9252 LCS 2

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int		ans[1001][1001];
char	save[1001];


int	main()
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
	int aa = a.length();
	int bb = b.length();
	while (aa != 0 && bb != 0) {
		if (ans[aa][bb] == ans[aa-1][bb])
			aa--;
		else if (ans[aa][bb] == ans[aa][bb-1])
			bb--;
		else {
			save[ans[aa][bb]-1] = a[aa-1];
			aa--;
			bb--;
		}
	}
	std::cout << ans[a.length()][b.length()] << '\n'; 
	std::cout << save << std::endl;

	return (0);
}