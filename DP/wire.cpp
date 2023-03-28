// Baekjoon
// 2565 전깃줄

#include <iostream>
#include <vector>

int	main()
{
	// input
	std::vector<std::pair<int, int> > ab;
	int	n;
	std::cin >> n;
	for(int i=0;i<n;++i)
	{
		int f, s;
		std::cin >> f >> s;
		ab.push_back(std::make_pair(f, s));
	}
	// solution
	for (auto i : ab)
		std::cout << i.first << ' ' << i.second << std::endl;
}