// Baekjoon
// 12015 가장 긴 증가하는 부분 수열 2

#include <iostream>

int	n;
int	arr[1000000];
int	res[1000000];

int	bin_search(int cnt, int i)
{
	int	start, end, mid;
	start = 0;
	end = cnt;
	
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (arr[i] > res[mid])
			start = mid + 1;
		else
			end = mid;
	}
	return (end);
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
	int	cnt = 1, idx;
	res[0] = arr[0];
	for (int i=0;i<n;++i) {
		if (res[cnt-1] < arr[i])
			res[cnt++] = arr[i];
		else {
			idx = bin_search(cnt, i);
			res[idx] = arr[i];
		}
	}
	std::cout << cnt << '\n';

	return (0);
}