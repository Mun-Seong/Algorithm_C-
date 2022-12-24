#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> dp(n+1, 0);
	dp[1] = 1;

	for (int i=2;i<=n;i++)
	{
		int i_min = 100000000;
		for (int j=1;j*j<=i; j++)
		{
			int t = i-j*j;
			i_min = min(i_min, dp[t]);
		}
		dp[i] = i_min + 1;
	}
	cout << dp[n];
}