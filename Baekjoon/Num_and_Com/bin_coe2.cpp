// Baekjoon
// 11051 이항 계수 2

#include <iostream>

// 팩토리얼은 시간 초과
// int factorial(int i)
// {
// 	if (i == 1 || i == 0)
// 		return (1);
// 	else
// 		return (i * factorial(i - 1));
// }


int main()
{
	int N, K;
	std::cin >> N >> K;
	
	int pascal_arr[N+1][N+1];
	for (int i=0;i<=N;++i)
		pascal_arr[i][0] = 1;
	for (int i=1;i<=N;i++)
	{
		for (int j=1;j<=i;j++)
		{
			if (j == i)
			{
				pascal_arr[i][j] = 1;
			}
			else
			{
				pascal_arr[i][j] = (pascal_arr[i-1][j-1] + pascal_arr[i-1][j]) % 10007;
			}
		}
	}
	std::cout << pascal_arr[N][K] << std::endl;
	// for (int i=0;i<=N;++i)
	// {
	// 	for (int j=0;j<=i;++j)
	// 		std::cout << pascal_arr[i][j] << ' ';
	// 	std::cout << '\n';
	// }
}