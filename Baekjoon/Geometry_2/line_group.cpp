// Baekjoon
// 2162 선분 그룹

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

bool	is_cross(line a, line b)
{
	int	aa = ccw(a.s, a.e, b.s) * ccw(a.s, a.e, b.e);
	int bb = ccw(b.s, b.e, a.s) * ccw(b.s, b.e, a.e);
	if (aa <= 0 && bb <= 0) {
		if (aa == 0 && bb == 0) {
			if (a.e <= a.s)	std::swap(a.e, a.s);
			if (b.e <= b.s)	std::swap(b.e, b.s);
			if (a.s <= b.e && b.s <= a.e)
				return (true);
			else
				return (false);
		}
		else
			return (true);
	}
	else
		return (false);
}

int		n, parent[3000];
line	lines[3000];

int find(int x) 
{
	if (parent[x] < 0) // 배열 인덱스와 값이 같다면 해당 값 리턴
		return x;
	return parent[x] = find(parent[x]); // 배열의 값을 인덱스로 갖는 값 리턴
}

void	f_union(int x, int y)
{
	x = find(x);
	y = find(y);
	if (parent[x] > parent[y]) {
		parent[y] += parent[x];
		parent[x] = y;
	}
	else {
		parent[x] += parent[y];
		parent[y] = x;
	}
}

bool isUnion(int x, int y) { // 두 노드가 연결되어있는지 판별하는 함수
	x = find(x);
	y = find(y);
	if (x == y)
		return true;
	return false;
}

int	main()
{
	// input
	std::cin >> n;
	for (int i=0;i<n;++i) {
		std::cin >> lines[i].s.x >> lines[i].s.y
				>> lines[i].e.x >> lines[i].e.y;
		parent[i] = -1;
	}

	// solution
	for (int i=0;i<n;++i) {
		for (int j=i+1;j<n;++j) {
			if (is_cross(lines[i], lines[j])) {
				if (!isUnion(i, j))
					f_union(i, j);
			}
		}
	}
	int	num_group(0), lagest(0);
	for (int i=0;i<n;++i) {
		if (parent[i] < 0) {
			num_group++;
			lagest = std::max(lagest, -1 * parent[i]);
		}	
	}
	if (num_group == 0)
		num_group = n;
	std::cout << num_group << '\n' << lagest << '\n';
	
	return (0);
}