// Baekjoon
// 1620 나는야 포켓몬 마스터 이다솜

#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M;
	std::string arr[100001];

	std::unordered_map<std::string, int> m;
	std::string tmp;

	std::cin >> N >> M;
	for (int i=1;i<=N;++i)
	{
		std::cin >> tmp;
		m.insert(make_pair(tmp, i));
		arr[i] = tmp; 
	}

	for (int i=0;i<M;++i)
	{
		std::cin >> tmp;
		int tmp_num = std::atoi(tmp.c_str());
		if(tmp_num == 0)
			std::cout << m.find(tmp)->second << '\n';
		else
			std::cout << arr[tmp_num] << '\n';
		// 아래 동작은 시간초과
		// else
		// {
		// 	for (auto j : m)
		// 	{
		// 		if (j.second == tmp)
		// 			std::cout << j.first << '\n';
		// 	}
		// }
	}
	return 0;
}