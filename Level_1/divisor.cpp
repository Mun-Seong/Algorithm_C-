#include <iostream>

using namespace std;
int	Sol(int n, int k)
{
	int i = 1;
	while (i <= n)
	{
		if (n % i == 0)
		{
			k--;
			if (k == 0)
				return (i);
		}
		i++;
	}
	return (0);
}

int	main(){
	int N, K;
	cin >> N >> K;
	cout << Sol(N, K);
}