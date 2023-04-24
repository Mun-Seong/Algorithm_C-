// Baekjoon
// 11066 파일 합치기

#include <iostream>
#include <algorithm>

int	t, k;
int	dp[501];
int	chap[500];

int	main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	// input
	std::cin >> t;

	for (int i=0;i<t;++i) {
		// input
		std::cin >> k;
		for (int j=0;j<k;++j) {
			std::cin >> chap[j];
		}
		// solution
	
		std::cout << dp[k-1] << '\n';
	}

	return (0);
}