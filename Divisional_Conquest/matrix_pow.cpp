// Baekjoon
// 10830 행렬 제곱

#include <iostream>
#include <vector>

typedef long long ll;
typedef std::vector<std::vector<ll>> mat;

int n, mod(1000);
long long b;

mat	operator * (const mat &a, const mat &b)
{
	int size = a.size();
	mat	ret(size, std::vector<ll>(size));

	for (int i=0;i<size;++i) {
		for (int j=0;j<size;++j) {
			for (int k=0;k<size;++k) {
				ret[i][j] += a[i][k] * b[k][j];
			}
			ret[i][j] %= mod;
		}
	}
	return (ret);
}

mat	speed_pow(mat a, ll b)
{
	int size = a.size();
	mat	ret(size, std::vector<ll>(size));
	// init
	for (int i=0;i<size;++i)
		ret[i][i] = 1;
	//speed_pow
	while (b > 0)
	{
		if (b % 2)
		{
			b--;
			ret = ret * a;
		}
		else
		{
			b /= 2;
			a = a * a;
		}
	}
	return (ret);
}

int main()
{
	// input
	std::cin >> n >> b;

	mat	input(n, std::vector<ll>(n));

	for (int i=0;i<n;++i) {
		for (int j=0;j<n;++j) {
			std::cin >> input[i][j];
		}
	}

	// solution
	mat ans = speed_pow(input, b);
	for (auto v : ans) {
		for (auto i : v) {
			std::cout << i << ' ';
		}
		std::cout << '\n';
	}
	return (0);
}