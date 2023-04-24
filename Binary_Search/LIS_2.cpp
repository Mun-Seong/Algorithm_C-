// Baekjoon
// 12015 가장 긴 증가하는 부분 수열 2

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int	n;
int	arr[1000000];
std::vector<int>	s;

void	binary_search(int i)
{
	int	start, end, mid, ret;
	start = 0;
	end = s.size() - 1;
	ret = INT_MAX;
	while (start <= end)
	{
		mid = (start + end) / 2;
		int mid_num = s[mid];
		if (mid_num >= i) {
			ret = std::min(ret, mid);
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	s[ret] = i;
}

void	find_lis(void)
{
	s.push_back(arr[0]);
	for (int i=1;i<n;++i) {
		if (s.back() < arr[i])
			s.push_back(arr[i]);
		else
			binary_search(arr[i]);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	// input
	std::cin >> n;
	for (int i=0;i<n;++i)
		std::cin >> arr[i];
	
	// solution
	find_lis();
	std::cout << s.size() << '\n';

	return (0);
}