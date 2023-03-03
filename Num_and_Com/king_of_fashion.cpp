// Baekjoon
// 9375 패션왕 신해빈

#include <iostream>
#include <string>
#include <map>

int main()
{
	int T, n;
	std::cin >> T;

	int ans[T];
	for (int i=0;i<T;++i)
	{
		std::cin >> n;
		std::map<std::string, int> m;
		std::string a,b;
		for (int j=0;j<n;++j)
		{
			std::cin >> a >> b;
			m[b]++;
		}
		ans[i] = 1;
		// 안입는 경우를 더해서 계산
		for (auto si : m)
			ans[i] *= (si.second + 1);
		ans[i]--; // 다 벗은 경우를 뺌
	}
	for (int i=0;i<T;++i)
		std::cout << ans[i] << '\n';
}