// Baekjoon
// 1912 연속합

#include <iostream>

int arr[100001];
int save[100001];

int	solution(int &n)
{
	int ret = arr[0];
	save[0] = arr[0];
	for (int i=1;i<n;++i)
	{
		save[i] = std::max(save[i-1] + arr[i], arr[i]);
		ret = std::max(save[i], ret);
	}
	return (ret);
}

int main()
{
	int n;
	std::cin >> n;
	for (int i=0;i<n;++i)
		std::cin >> arr[i];

	std::cout << solution(n) << std::endl;
}
