// Baekjoon
// 2166 다각형의 면적

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int			n;
double		points[10001][2];

double	get_triangle_area(double a[2], double b[2], double c[2])
{
	// use shoe strap formula
	double	i = (a[0] * b[1]) + (b[0] * c[1]) + (c[0] * a[1]);
	double	j = (a[1] * b[0]) + (b[1] * c[0]) + (c[1] * a[0]);
	double	ret = i - j;
	return (ret/2);
}

int	main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	// input
	double	ans(0);
	std::cin >> n;
	for (int i=0;i<n;++i)
		std::cin >> points[i][0] >> points[i][1];

	// solution	- choose 3 points and get triangle area and sum that adouble
	for (int i=1;i<n-1;++i) {
		ans += get_triangle_area(points[0], points[i], points[i+1]);
	}
	std::cout << std::fixed;
	std::cout.precision(1);
	// func abs and std::abs
	std::cout << std::abs(ans) << '\n';
	return (0);
}