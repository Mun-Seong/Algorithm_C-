// Baekjoon
// 11723 집합

#include <iostream>
#include <string>

int			s, m;

int	main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	// input
	std::cin >> m;
	for (int i=0;i<m;++i) {
		std::string	cmd;
		int			x;
		std::cin >> cmd;
		if (cmd == "add") {
			std::cin >> x;
			s = s | (1 << x);
		}
		else if (cmd == "remove") {
			std::cin >> x;
			s = s & ~(1 << x);
		}
		else if (cmd == "check") {
			std::cin >> x;
			if (s & (1 << x))
				std::cout << "1\n";
			else
				std::cout << "0\n";
		}
		else if (cmd == "toggle") {
			std::cin >> x;
			if (s & (1 << x))
				s = s & ~(1 << x);
			else
				s = s | (1 << x);
		}
		else if (cmd == "all") {
			s = (1 << 21) - 1;	// 20bit를 1로 설정
		}
		else if (cmd == "empty") {
			s= 0;
		}
	}

	return (0);
}