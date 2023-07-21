// Baekjoon
// 4195 친구 네트워크

#include <iostream>
#include <map>
#include <string>

std::map<std::string, std::string>	m;
std::map<std::string, int>			nm;
int	t, f;

std::string	find(std::string s)
{
	if (m[s] == s) // 배열 인덱스와 값이 같다면 해당 값 리턴
		return s;
	return m[s] = find(m[s]); // 배열의 값을 인덱스로 갖는 값 리턴
}

void	f_union(std::string s1, std::string s2)
{
	s1 = find(s1);
	s2 = find(s2);
	if (s1 == s2)	return;
	m[s2] = s1;
	nm[s1] += nm[s2];
}

bool isUnion(std::string s1, std::string s2) { // 두 노드가 연결되어있는지 판별하는 함수
	s1 = find(s1);
	s2 = find(s2);
	if (s1 == s2)
		return true;
	return false;
}

int	main()
{
	// input
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	
	std::cin >> t;
	for (int tt=1;tt<=t;++tt) {
		// init
		nm.clear();
		m.clear();

		std::cin >> f;

		// solution
		for (int i=0;i<f;++i) {
			std::string	s1, s2;
			std::cin >> s1 >> s2;
			if (m.find(s1) == m.end()) {	// s1이 존재x
				m.insert({s1, s1});
				nm.insert({s1, 1});
			}
			if (m.find(s2) == m.end()) {
				m.insert({s2, s2});
				nm.insert({s2, 1});
			}
			f_union(s1, s2);
			std::cout << nm[find(s1)] << '\n';
		}
	}

	return (0);
}