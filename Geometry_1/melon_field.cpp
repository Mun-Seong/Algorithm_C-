// Baekjoon
// 2477 참외밭

#include <iostream>

int main()
{
	// input
	int K, dir[12], dist[12];

	std::cin >> K;
	for (int i=0; i<6; ++i)
		std::cin >> dir[i] >> dist[i];
	
	// solution
	// 방향이 3131 or 4242 등과 같이 나오면 큰 직사각형과
	// 작은 직사각형의 크기를 알 수 있음
	// 하지만 134213, 342131 같은 
	// 연속적이지 않게 방향이 틀어지면 문제가 발생
	// 해결 방법 크기가 8인 배열로 만들어 앞의 2개를 복사

	// 넓이를 구하기 위해서 들어온 방향을 복사해서 2배로 저장
	for (int i=0;i<6;++i)
	{
		dir[i+6] = dir[i];
		dist[i+6] = dist[i];
	}
	int big(0), small(0);

	for (int i=0; i<7; ++i)
	{
		if (dir[i] == dir[i+2] && dir[i+1] == dir[i+3])
		{
			big = dist[i+4] * dist[i+5];
			small = dist[i+1] * dist[i+2];
		}
	}
	std::cout << K * (big - small) << std::endl;

	return (0);
}
