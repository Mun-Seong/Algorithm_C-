// Baekjoon
// 11758 CCW

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int		points[3][2];

int	main()
{
	// input
	for (int i=0;i<3;++i)
		std::cin >> points[i][0] >> points[i][1];
	
	// solution
	int	res = (points[1][0] - points[0][0]) * (points[2][1] - points[0][1])
			- (points[2][0] - points[0][0]) * (points[1][1] - points[0][1]);
	if (res == 0)
		std::cout << "0";
	else if (res > 0)
		std::cout << "1";
	else
		std::cout << "-1";
	std::cout << '\n';
	
	return (0);
}