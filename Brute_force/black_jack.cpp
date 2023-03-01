#include <iostream>

using namespace std;

int N, M;
int deck[100];

int new_black_jack(int n, int m)
{
	int x = 0;
	for (int i=0; i<n ; ++i)
	{
		for (int j=i+1; j<n ; ++j)
		{
			if (deck[i] + deck[j] >= m)
				continue;
			for (int k=j+1; k<n ; ++k)
			{
				if (deck[i] + deck[j] + deck[k] > m)
					continue;
				x = max(x, deck[i] + deck[j] + deck[k]);
				if (x == m)
					return (x);
			}
		}
	}
	return (x);
}

int main()
{
	cin >> N >> M;
	for (int i=0; i<N; ++i)
		cin >> deck[i];
	cout << new_black_jack(N, M) << endl;
}