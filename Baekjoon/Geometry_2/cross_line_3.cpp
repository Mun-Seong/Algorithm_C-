// Baekjoon
// 20149 선분 교차 3

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
			return (y <= a.y);
		return (x <= a.x);
	}
	bool operator == (const s_point &a) const
	{
		return (x == a.x && y == a.y);
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

void	get_cross_point(void)
{
	point	ab = a.s - a.e, cd = b.s - b.e;
	double	da = ab.x * cd.y;
	double	db = ab.y * cd.x;

	std::cout << std::fixed;
	std::cout.precision(9);
	if (da - db == 0) {
		if (a.e == b.s)
			std::cout << a.e.x << ' ' << a.e.y << '\n';
		else if (a.s == b.e)
			std::cout << a.s.x << ' ' << a.s.y << '\n';
		return ;
	}
	double	daa = (a.s.x * a.e.y) - (a.s.y * a.e.x);
	double	dbb = (b.s.x * b.e.y) - (b.s.y * b.e.x);

	double	x = ((daa * cd.x) - (ab.x * dbb))
				/ (da - db);
	double	y = ((daa * cd.y) - (ab.y * dbb))
				/ (da - db);
	std::cout << x << ' ' << y << '\n';
}

int	main()
{
	// input
	std::cin >> a.s.x >> a.s.y >> a.e.x >> a.e.y;
	std::cin >> b.s.x >> b.s.y >> b.e.x >> b.e.y;

	// solution
	int	aa = ccw(a.s, a.e, b.s) * ccw(a.s, a.e, b.e);
	int bb = ccw(b.s, b.e, a.s) * ccw(b.s, b.e, a.e);
	// 교차 예정
	if (aa <= 0 && bb <= 0) {
		if (aa == 0 && bb == 0) {
			if (a.e <= a.s)	std::swap(a.e, a.s);
			if (b.e <= b.s)	std::swap(b.e, b.s);
			if (a.s <= b.e && b.s <= a.e) {
				std::cout << 1 << '\n';
				if (a.s == b.s || a.s == b.e || a.e == b.s || a.e == b.e)
					get_cross_point();
			}
			else
				std::cout << 0 << '\n';
		}
		else {
			std::cout << 1 << '\n';
			get_cross_point();
		}
	}
	else
		std::cout << 0 << '\n';
	
	return (0);
}