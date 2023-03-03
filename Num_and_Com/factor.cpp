// Baekjoon
// 1037 약수

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int	N, tmp;
	std::vector<int> v;

	std::cin >> N;
	for (int i=0;i<N;++i)
	{
		std::cin >> tmp;
		v.push_back(tmp);
	}
	std::sort(v.begin(), v.end());
	std::cout << (*(v.begin())) * (*(--v.end())) << '\n';
}