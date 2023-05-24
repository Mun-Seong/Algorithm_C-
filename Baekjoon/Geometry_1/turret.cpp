// Baekjoon
// 1002 터렛

#include <iostream>
#include <cmath>

typedef struct s_cir
{
	int	x;
	int y;
	int rad;
} t_cir;

int get_points(t_cir &c1, t_cir &c2)
{
	int ret;
	double	dist;
	dist = sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
	
	// 외접
	if ((c1.rad + c2.rad) == dist)
		return 1;
	// 접점 x
	else if ((c1.rad + c2.rad) < dist)
		return 0;
	// 두 점
	else if (abs(c1.rad - c2.rad) < dist && 
		dist < (c1.rad + c2.rad))
		return 2;
	// 내접 or 같은 원
	else if (abs(c1.rad - c2.rad) == dist)
	{
		// 같은 원
		if (c1.rad == c2.rad)
			return -1;
		return 1;
	}
	// 안에서 만나지 않음
	else
		return 0;
}

int main()
{
	int T;
	std::cin >> T;

	int ans[T];
	t_cir c1, c2;
	for (int i=0;i<T;++i)
	{
		std::cin >> c1.x >> c1.y >> c1.rad 
			>> c2.x >> c2.y >> c2.rad;
		ans[i] = get_points(c1, c2);
	}
	for (int i=0;i<T;++i)
		std::cout << ans[i] << '\n'; 
}