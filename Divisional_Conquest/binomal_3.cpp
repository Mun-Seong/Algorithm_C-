// Baekjoon
// 11401 이항 계수 3

#include <iostream>
#include <cmath>

long long MOD = 1000000007;

int n ,k;

long long	speed_pow(int a, int b)
{
	if (b == 0)
		return (1);
	if (b % 2)
		return (a * speed_pow(a, b - 1) % MOD);
	long long tmp = speed_pow(a, b / 2);
	return (tmp * tmp % MOD);
}

int main()
{
	// input
	std::cin >> n >> k;
	// solution
	long long a = 1, b = 1;
	// a = n*..*n-k+1
	for (int i=n;i>=n-k+1;--i)	a = (a*i) % MOD;
	// b = k!
	for (int i=1;i<=k;++i)		b = (b*i) % MOD;
	b = speed_pow(b, MOD - 2);
	std::cout << a * b % MOD << '\n';
	return (0);
}