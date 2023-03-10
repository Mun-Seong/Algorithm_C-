// Baekjoon
// 9461 파도반 수열

#include <iostream>
#include <vector>

int 			T;
std::vector<long long> ans;
long long 		arr[101];

//init arr[1] - arr[10] = 1, 1, 1, 2, 2, 3, 4, 5, 7, 9
long long	solution(int n)
{
	if (n < 3)
		return (arr[n]);
	else if (arr[n] == 0)
		arr[n] = solution(n-2) + solution(n-3);
	return (arr[n]);
}

int main()
{
	int N;

	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 1;
	std::cin >> T;
	for (int i=0;i<T;++i)
	{
		std::cin >> N;
		ans.push_back(solution(N));
	}
	for (long long a : ans)
		std::cout << a << '\n';
}