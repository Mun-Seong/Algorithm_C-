#include <iostream>

using namespace std;

int main()
{
	/** input */
	int N, K, answer;
	cin >> N >> K;
	int coins[N];
	for (int i=0;i<N;++i)
		cin >> coins[i];
	/** solution */
	for (int i = N-1;i > 0; --i)
	{
		if (K - coins[i] >= 0)
		{
			while (K - coins[i] >= 0)
			{
				K -= coins[i];
				++answer; 
			}
		}
	}
	
}