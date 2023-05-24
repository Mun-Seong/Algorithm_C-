// Baekjoon
// 10815 숫자 카드

#include <iostream>
#include <set>

int N, M;

int main()
{	/**
 	* 아래 문구를 입력하지 않았을 때 시간 초과가 뜸
 	* 11-12 line을 통해 버퍼의 속도를 높여 해결
 	*/
	std::ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);

	std::set<int> n;
	int tmp;

	std::cin >> N;
	for (int i=0;i<N;++i)
	{
		std::cin >> tmp;
		n.insert(tmp);
	}
	std::cin >> M;
	for (int i=0;i<M;++i)
	{
		std::cin >> tmp;
		if (n.find(tmp) == n.end())
			std::cout << 0;
		else
			std::cout << 1;
		std::cout << ' ';
	}
	std::cout << std::endl;
	return 0;
}