#include <iostream>
using namespace std;

int n, k;
int coin[101];
int DP[10001];

void	slove()
{
	for (int i=0;i<n;i++)
	{
		DP[0] = 0;
		for (int j=coin[i];j<=k;j++)
		{
			int a = DP[j - coin[i]] + 1;
			DP[j] = min(DP[j], a);
		}
	}
	if (DP[k] == 10001) cout << -1;
	else cout << DP[k];
}

int main()
{
	cin >> n >> k;
	for (int i=0;i<n;i++)
		cin >> coin[i];
	fill_n(DP, k+1, 10001);
	slove();
}