// Baekjoon
// 1904 01타일

#include <iostream>

int N, ans[1000001];

void	solution(void)
{
	ans[1] = 1;
	ans[2] = 2;
	for (int i=3;i<=N;++i)
	{
		ans[i] = (ans[i-1] + ans[i-2]) % 15746; 
	}
}

int main()
{
	std::cin >> N;
	solution();
	std::cout << ans[N] << std::endl;
}