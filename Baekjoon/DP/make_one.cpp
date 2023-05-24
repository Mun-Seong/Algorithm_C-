// Baekjoon
// 1463 1로 만들기

#include <iostream>

int ans[3000001];

int main()
{
	// input
	int N;

	std::cin >> N;
	// solution
	int i = 1;
	ans[i] = 0;
	while(1)
	{
		if (ans[i+1] == 0)
			ans[i+1] = ans[i] + 1;
		else
			ans[i+1] = std::min(ans[i+1], ans[i]+1);
		if (i + 1 >= N)
			break;
		if (ans[i*2] == 0)
			ans[i*2] = ans[i] + 1;
		else
			ans[i*2] = std::min(ans[i*2], ans[i]+1);
		if (ans[i*3] == 0)
			ans[i*3] = ans[i] + 1;
		else
			ans[i*3] = std::min(ans[i*3], ans[i]+1);
		++i;
	}
	std::cout << ans[N] << std::endl;
}