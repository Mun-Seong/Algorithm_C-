// Baekjoon
// 1764 듣보잡

#include <iostream>
#include <string>
#include <unordered_set>
#include <set>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M;
	std::string tmp;
	std::unordered_set<std::string> s;
	std::set<std::string> v; 

	std::cin >> N >> M;
	for (int i=0;i<N;++i)
	{
		std::cin >> tmp;
		s.insert(tmp);
	}
	for (int i=0;i<M;++i)
	{
		std::cin >> tmp;
		if (s.find(tmp) != s.end())
			v.insert(tmp);
	}
	std::cout << v.size() << '\n';
	for (auto aa : v)
		std::cout << aa << '\n';
}