// Baekjoon
// 1934 최소공배수

#include <iostream>

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return (a);
}

int lcm(int a, int b)
{
	return (a * b / gcd(a, b));
}

int main()
{
	int T, a, b;
	std::cin >> T;

	int ans[T];
	for (int i=0;i<T;++i)
	{
		std::cin >> a >> b;
		ans[i] = lcm(a, b);
	}
	for (int i=0;i<T;++i)
		std::cout << ans[i] << '\n';
}