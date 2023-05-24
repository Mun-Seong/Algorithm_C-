// Baekjoon
// 11478 서로 다른 부분 문자열의 개수

#include <iostream>
#include <string>
#include <unordered_set>

int main()
{
	std::ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);

	std::string						s;
	std::unordered_set<std::string>	sub;

	std::cin >> s;
	for (int gab=1; gab<s.length(); ++gab)
	{
		for (int i=0; i<s.length(); ++i)
			sub.insert(s.substr(i, gab));
	}
	std::cout << sub.size() + 1 << std::endl;
}