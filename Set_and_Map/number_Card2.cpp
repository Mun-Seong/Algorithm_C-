// Baekjoon
// 10816 숫자 카드 2

#include <iostream>
#include <unordered_map>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M, tmp;
	std::unordered_map<int, int> m;

	std::cin >> N;
	for (int i=0;i<N;++i)
	{
		std::cin >> tmp;
		if (m.find(tmp) == m.end())
			m.insert({tmp, 1});
		else
			m[tmp]++;
	}

	std::cin >> M;
	for (int i=0; i<M;++i)
	{
		std::cin >> tmp;
		if (m.find(tmp) == m.end())
			std::cout << 0 << ' ';
		else
			std::cout << m[tmp] << ' ';
	}
	std::cout << std::endl;
}