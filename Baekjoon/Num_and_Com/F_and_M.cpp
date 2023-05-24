// Baekjoon
// 5086 배수와 약수

#include <iostream>
#include <string>
#include <vector>

int main()
{
	int a, b;
	std::vector<std::string> v;

	while (1)
	{
		std::cin >> a >> b;
		if (!a && !b)
			break;
		if (b % a == 0)
			v.push_back("factor");
		else if (a % b == 0)
			v.push_back("multiple");
		else
			v.push_back("neither");
	}
	for (std::string s : v)
		std::cout << s << '\n';
	return (0);
}