// Baekjoon
// 1717 집합의 표현

#include <iostream>

int	n, m;
int	set[1000001];

int	get_root(int i)
{
	if (set[i] == i)
		return (i);
	return (set[i] = get_root(set[i]));
}

int	main()
{
	// input
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> n >> m;
	// init_set
	for (int i=1;i<=n;++i)
		set[i] = i;
	for (int i=0;i<m;++i) {
		// solution
		int	cal, a, b;
		std::cin >> cal >> a >> b;
		if (cal) {	// 1 a b
			if (get_root(a) == get_root(b))
				std::cout << "YES\n";
			else
				std::cout << "NO\n";
		}
		else {	// 0 a b
			set[get_root(b)] = get_root(a);
		}
	}

	return (0);
}