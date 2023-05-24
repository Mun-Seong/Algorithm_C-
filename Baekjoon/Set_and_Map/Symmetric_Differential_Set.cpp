// Baekjoon
// 1269 대칭 차집합

#include <iostream>
#include <string>
#include <unordered_set>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int A, B, tmp, ans(0);
	std::unordered_set<int> s1;
	std::cin >> A >> B;
	for (int i=0;i<A;++i)
	{
		std::cin >> tmp;
		s1.insert(tmp);
	}
	for (int i=0;i<B;++i)
	{
		std::cin >> tmp;
		if (s1.find(tmp) == s1.end())
			ans++;
		else
			s1.erase(tmp);
	}
	ans += s1.size();
	std::cout << ans << '\n';
}