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
	bool operator <= (const s_point &a) const
	{
		if (x == a.x)
			return (y<=a.y);
		return (x <= a.x);
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
	int	aa = ccw(a.s, a.e, b.s) * ccw(a.s, a.e, b.e);
	int bb = ccw(b.s, b.e, a.s) * ccw(b.s, b.e, a.e);
	if (aa <= 0 && bb <= 0) {
		if (aa == 0 && bb == 0) {
			if (a.e <= a.s)	std::swap(a.e, a.s);
			if (b.e <= b.s)	std::swap(b.e, b.s);
			if (a.s <= b.e && b.s <= a.e)
				std::cout << 1;
			else
				std::cout << 0;
		}
		else
			std::cout << 1;
	}
	else
		std::cout << 0;
	std::cout << '\n';
	
	return (0);
}