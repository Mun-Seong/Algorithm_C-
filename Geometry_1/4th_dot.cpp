// Baekjoon
// 3009 네 번째 점

#include <iostream>

int main()
{
	int x, y;
	std::pair<int ,int>	point[4];
	for (int i=0; i<3; ++i)
	{
		std::cin >> x >> y;
		point[i].first = x;
		point[i].second = y;
	}
	if (point[0].first == point[1].first)
		point[3].first = point[2].first;
	else if(point[0].first == point[2].first)
		point[3].first = point[1].first;
	else
		point[3].first = point[0].first;
	
	if (point[0].second == point[1].second)
		point[3].second = point[2].second;
	else if(point[0].second == point[2].second)
		point[3].second = point[1].second;
	else
		point[3].second = point[0].second;

	std::cout << point[3].first << ' ' << point[3].second << std::endl;
}