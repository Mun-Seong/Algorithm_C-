// Baekjoon
// 14425 문자열 집합

#include <iostream>
#include <string>
#include <set>


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M, ans(0);
	std::string tmp;
	std::set<std::string> s;

	std::cin >> N >> M;
	for (int i=0;i<N;++i)
	{
		std::cin >> tmp;
		s.insert(tmp);
	}
	for (int i=0;i<M;++i)
	{
		std::cin >> tmp;
		if (s.find(tmp) == s.end())
			continue;
		ans++;
	}
	std::cout << ans << std::endl;
}