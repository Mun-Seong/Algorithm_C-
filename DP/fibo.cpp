// Baekjoon
// 24416 알고리즘 수업 - 피보나치 수 1

#include <iostream>

int N, cnt(0), count(0);
int f[41];

int fib(int n)
{
	if (n == 1 || n == 2)
	{
		cnt++;
		return 1;
	}
	else
		return (fib(n-1) + fib(n-2));
}

int fibonacci(int n) {
	f[1] = f[2] = 1;
	for (int i=3;i<=n;++i)
	{
		f[i] = f[i - 1] + f[i - 2];
		count++;
	}
	return f[n];
}

int main()
{
	std::cin >> N;
	fib(N);
	fibonacci(N);
	std::cout << cnt << ' ' << count << std::endl;
}