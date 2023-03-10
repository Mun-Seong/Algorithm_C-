// Baekjoon
// 1149 RGB거리

#include <iostream>

typedef struct s_rgb
{
	/* data */
	int r;
	int g;
	int b;
}	t_rgb;

t_rgb	s[1001];

int main()
{
	int		N;
	t_rgb	save;

	std::cin >> N;
	for (int i=1;i<=N;++i)
	{
		std::cin >> save.r >> save.g >> save.b;
		s[i].r = std::min(s[i-1].g, s[i-1].b) + save.r;
		s[i].g = std::min(s[i-1].r, s[i-1].b) + save.g;
		s[i].b = std::min(s[i-1].g, s[i-1].r) + save.b;
	}
	std::cout << std::min(s[N].r, std::min(s[N].g, s[N].b)) << std::endl;
}