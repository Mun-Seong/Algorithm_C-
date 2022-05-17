#include <iostream>

using namespace std;

int n, k;
int coin[101];
int DP[10001];

void	slove()
{
	DP[0] = 1;
	for (int i=0;i<n;i++)
	{
		for (int j = coin[i];j<=k;j++)
		{
			DP[j] = DP[j] + DP[j - coin[i]];
		}
	}
	cout << DP[k];
}

int main()
{
	cin >> n >> k;
	for (int i=0;i<n;i++)
		cin >> coin[i];
	
	slove();
}