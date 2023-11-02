// Baekjoon
// 1086번 박성원

#include <iostream>
#include <algorithm>
#include <string>

int				n, k;
int				ten_mod_k[51];
int				set_mod_k[15];
long long int	dp[1 << 15][101];
std::string		set[15];

long long int	get_gcd(long long int all, long long int part)
{
	while (part != 0) {
		long long mod = all % part;
		all = part;
		part = mod;
	}
	return (all);
}

int	main()
{
	// input
	std::cin >> n;
	for (int i=0;i<n;++i)
		std::cin >> set[i];
	std::cin >> k;

	// solution	x % k = 0
	// ex) 123456 % k = ((123 % k)*(100 % k) + 456 % k) % k
	
	// save mods of k in 10^i
	ten_mod_k[0] = 1 % k;
	for (int i=1;i<51;++i)
		ten_mod_k[i] = (ten_mod_k[i-1] * 10) % k;
	
	// save mods of k in set
	for (int i=0;i<n;++i) {
		int	smk	= 0;
		for (int j=0;j<set[i].length();++j) {
			smk *= 10;
			smk += set[i][j] - '0';
			smk %= k;
		}
		set_mod_k[i] = smk;
	}

	// dp[state][mod_k] calculation
	dp[0][0] = 1;
	for (int state=0;state < (1 << n);++state) {
		for (int i=0;i<n;++i) {
			if (state & (1 << i))	continue;
			int	next_state = state | (1 << i);
			for (int j=0;j<k;++j) {
				int	next_k = ((j * ten_mod_k[set[i].length()]) % k
							+ set_mod_k[i]) % k;
				dp[next_state][next_k] += dp[state][j];
			}
		}
	}

	long long int	all, part, gcd;
	all = 1;
	for (int i=1;i<=n;++i)
		all *= i;
	part = dp[(1 << n) - 1][0];
	gcd = get_gcd(all, part);
	all /= gcd;	part /= gcd;

	std::cout << part << '/' << all << '\n'; 

	return (0);
}