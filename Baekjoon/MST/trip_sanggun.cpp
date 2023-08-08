// Baekjoon
// 9372 상근이의 여행

#include <iostream>
#include <vector>
#include <cstring>

typedef std::vector<int>	vi;

int		n, m, t;

int	main()
{
	// input
	std::cin >> t;
	for (int tt=0;tt<t;++tt) {
		// input_2
		std::cin >> n >> m;
		for (int i=0;i<m;++i) {
			int	a, b;
			std::cin >> a >> b;
		}
		// solution
		std::cout << n - 1 << '\n';
	}
	return (0);
}