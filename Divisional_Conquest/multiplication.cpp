// Baekjoon
// 1629 곱셈

#include <iostream>

int	x, y, z;

long long int	speed_pow(int a, int b, int c)
{
	if (b == 1)
		return (a % c);
	long long int k = speed_pow(a, b / 2, c) % c;
	if (b % 2)
		return (k * k % c * a % c);
	return (k * k % c);
}

int main()
{
	// input
	std::cin >> x >> y >> z;

	// solution
	std::cout << speed_pow(x, y, z) << '\n';
	return (0);
}