// Baekjoon
// 25308 방사형 그래프

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

typedef	struct s_point
{
	/* data */
	long long	x;
	long long	y;
	s_point operator - (const s_point &a) const
	{	
		s_point	ret;
		ret.x = x - a.x;
		ret.y = y - a.y;
		// std::cout << ret.x << ',' << ret.y << '\n'; 
		return (ret);
	}
}	point;

typedef	struct s_line
{
	/* data */
	point	s;
	point	e;
}	line;

int	ccw(point a, point b, point c)
{
	point	ab = b - a, ac = c - a;
	long long	ll = (ab.x * ac.y) - (ab.y * ac.x);
	if (ll > 0)			return (1);
	else if (ll < 0)	return (-1);
	else				return (0);
}

line	a, b;

int	main()
{
	// input
	std::cin >> a.s.x >> a.s.y >> a.e.x >> a.e.y;
	std::cin >> b.s.x >> b.s.y >> b.e.x >> b.e.y;

	// solution
	if (ccw(a.s, a.e, b.s) * ccw(a.s, a.e, b.e) <= 0
		&& ccw(b.s, b.e, a.s) * ccw(b.s, b.e, a.e) <= 0)
		std::cout << 1;
	else
		std::cout << 0;
	std::cout << '\n';
	
	return (0);
}