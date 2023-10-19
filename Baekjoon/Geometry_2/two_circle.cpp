// Baekjoon
// 7869 두 원

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

typedef	struct s_point
{
	/* data */
	double	x;
	double	y;
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

typedef struct	s_circle
{
	point		center;
	double	radius;
}	circle;

// a부채꼴 넓이 - a삼각형 + b부채꼴 넓이  - b삼각형
// 삼각형 넓이 = r * r * sin(a) / 2

circle a, b;

int	main()
{
	// input
	std::cin >> a.center.x >> a.center.y >> a.radius;
	std::cin >> b.center.x >> b.center.y >> b.radius;

	// solution
	double	res;
	point	temp = b.center - a.center;
	double	dist = sqrt((temp.x * temp.x) + (temp.y) * (temp.y));
	// 곂치지 않을 때
	if (a.radius + b.radius <= dist)
		res = 0.0;
	// 원 안에 존재 할 때
	else if (fabs(a.radius - b.radius) >= dist)
		res = M_PI * fmin(a.radius * a.radius, b.radius * b.radius);
	// 곂칠 때
	else {
		double		a_angle, b_angle;
		a_angle = acos((dist * dist + a.radius * a.radius - b.radius * b.radius)
						/ (dist * a.radius * 2.0)) * 2.0;
		b_angle = acos((dist * dist + b.radius * b.radius - a.radius * a.radius)
						/ (dist * b.radius * 2.0)) * 2.0;
		
		double a_sec, b_sec, a_tri, b_tri;
		a_sec =	a.radius * a.radius * a_angle;
		b_sec = b.radius * b.radius * b_angle;
		a_tri = a.radius * a.radius * sin(a_angle);
		b_tri = b.radius * b.radius * sin(b_angle);

		res = (a_sec + b_sec - a_tri - b_tri) * 0.5; 
	}
	std::cout << std::fixed;
	std::cout.precision(3);
	std::cout << res << '\n';

	return (0);
}