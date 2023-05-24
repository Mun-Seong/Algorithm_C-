// Baekjoon
// 9935 문자열 폭발

#include <iostream>
#include <string>

int	main()
{
	// input
	std::string	s, e, ans;
	std::cin >> s >> e;

	// solution
	// time over
	// while (s.find(e) != std::string::npos)
	// 	s.replace(s.find(e), e.length(), "");
	for (int i=0;i<s.length();++i) {
		ans += s[i];
		if (ans.length() >= e.length()) {
			bool flag = true;
			for (int j=0;j<e.length();++j) {
				if (ans[ans.length()-e.length()+j] != e[j]) {
					flag = false;
					break ;
				}
			}
			if (flag)
				ans.erase(ans.end() - e.length(), ans.end());
		}
	}
	if (ans.empty())
		std::cout << "FRULA\n";
	else
		std::cout << ans << '\n';
	return (0);
}