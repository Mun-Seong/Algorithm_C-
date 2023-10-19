// Baekjoon
// 1069 집으로

#include <iostream>
#include <cmath>

int	x, y, d, t;

int	main()
{

	// input
	std::cin >> x >> y >> d >> t;

	// solution
	double	time(0);
	double	dist = sqrt((x * x) + (y * y));
	int		jump = dist / d;
	double	reamin = dist - (jump * d);

	time = std::min(std::min(dist, jump * t + reamin),
					(jump + 1) * d - dist + (jump + 1) * t);
	if (jump > 0)
		time = std::min(time, double(jump + 1) * t);
	else if (dist < d)
		time = std::min(time, t * 2.0);

	std::cout << std::fixed;
	std::cout.precision(9);
	std::cout << time << '\n';
	
	return (0);
}