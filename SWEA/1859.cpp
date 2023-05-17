// SWEA
// 1859 백만 장자 프로젝트

#include <iostream>
#include <cstring>

int	t, n;
int	day[1000000];

int	main()
{
	// input
	std::cin >> t;
	for (int tt=1;tt<=t;++tt) {
		long long 	ans(0), buy(0), cost(0);

		memset((void*)day, 0, sizeof(day));
		std::cin >> n;
		for (int i=0;i<n;++i)
			std::cin >> day[i];
		// solution
		int	max_cost = day[n-1];
		for (int i=n-1;i>0;--i) {
			if (day[i] > max_cost)
				max_cost = day[i];
			if (max_cost > day [i-1])
				ans += max_cost - day[i-1];
		}
		std::cout << "#" << tt << ' ' << ans << '\n';
	}
	return (0);
}