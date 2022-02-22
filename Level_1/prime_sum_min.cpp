#include <iostream>
using namespace std;

bool	is_prime(int n)
{
	if (n == 1) return (false);
	for (int i = 2; i < n; i++)
		if (n % i == 0) return (false);
	return (true);
}

int main()
{
	int M, N, min_prime, sum_prime(0);
	bool is_min(true), has_prime(false);
	cin >> M;
	cin >> N;
	for (int i = M; i <= N; i++)
	{
		if (is_prime(i))
		{
			sum_prime += i;
			if (is_min)
			{	
				min_prime = i;
				is_min = false;
			}
			has_prime = true;
		}
	}
	if (has_prime)
		cout << sum_prime << endl << min_prime;
	else
		cout << -1;
}