#include <iostream>
int dp[251][251];

int binomial(int n, int r) {
	
	if(r == 0 || n == r) 
		return 1;
	if(dp[n][r] == 0) 
		dp[n][r] = (binomial(n - 1, r - 1) + binomial(n - 1, r));
	return dp[n][r] % 10000019;
}
int main()
{
	int n, k;
	std::cin >> n >> k;

	std::cout << binomial(n, k);
}