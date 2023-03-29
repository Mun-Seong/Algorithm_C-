// Baekjoon
// 16139 인긴-컴퓨터 상호작용

#include <iostream>
#include <string>

int sum[26][200001];
int	last_idx[26];

int	main()
{
	// input
	std::ios_base::sync_with_stdio(false); 
	std::cout.tie(NULL); 
	std::cin.tie(NULL);

	std::string	s;
	int			q;

	std::cin >> s;
	std::cin >> q;
	// solution
	for (int i=1;i<=s.length();++i)
	{
		int id = s[i-1] - 'a';
		for (int j=0;j<26;++j)
		{
			if (j == id)
				sum[j][i] = sum[j][i-1] + 1;
			else
				sum[j][i] = sum[j][i-1];
		}
	}
	for (int i=0;i<q;++i)
	{
		char	a;
		int		l, r;
		std::cin >> a >> l >> r;
		std::cout << sum[a - 'a'][r+1] - sum[a - 'a'][l] << '\n';
	}
}
