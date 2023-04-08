// Baekjoon
// 1541 잃어버린 괄호

#include <iostream>
#include <string>

int main()
{
	// input
	std::string	s, single_num;
	int			res(0);
	bool		is_minus(false);

	std::cin >> s;
	
	// solution
	for (int i=0;i<=s.size();++i)
	{
		if (s[i] == '-' || s[i] == '+' || i == s.size())
		{
			if (is_minus)
				res -= std::stoi(single_num);
			else
				res += std::stoi(single_num);
			single_num = "";
			if (s[i] == '-')
				is_minus = true;
		}
		else
			single_num += s[i];
	}
	std::cout << res << std::endl;

	return (0);
}