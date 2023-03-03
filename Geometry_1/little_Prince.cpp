// Baekjoon
// 1004 어린 왕자

#include <iostream>
#include <cmath>

typedef struct s_point {
	int x;
	int y;
}	t_point;

typedef struct s_cir {
	t_point	pos;
	int		rad;
}	t_cir;

double	get_dist(const t_point &p1, const t_point &p2)
{
	double ret;
	ret = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	return (ret);
}

bool	is_inside(const t_cir c, const t_point p)
{
	if (get_dist(p, c.pos) < c.rad)
		return (true);
	else
		return (false);
}

/* 출발점과 도착점이 어느 원 안에 있는지 로 판단이 가능 */
int solution(t_point &s, t_point &e, t_cir *cirs, int n)
{
	int ret(0);
	for(int i=0;i<n;++i)
	{
		if (is_inside(cirs[i], s) != is_inside(cirs[i], e))
			ret++; 
	}
	return (ret);
}

int main()
{
	int T, n;
	t_point s, e;
	std::cin >> T;
	int ans[T];
	for (int t=0;t<T;++t)
	{
		std::cin >> s.x >> s.y >> e.x >> e.y;
		std::cin >> n;
		t_cir	cirs[n];
		for (int i=0;i<n;++i)
			std::cin >> cirs[i].pos.x >> cirs[i].pos.y >> cirs[i].rad;
		
		ans[t] = solution(s, e, cirs, n);
	}
	for (int i=0;i<T;++i)
		std::cout << ans[i] << '\n';
}