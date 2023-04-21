// Baekjoon
// 2805 나무 자르기

#include <iostream>
#include <algorithm>

int n, m;
int	tree[1000000];

typedef unsigned long long ull;

int main()
{
	// input
	std::cin >> n >> m;
	for (int i=0;i<n;++i) {
		std::cin >> tree[i];
	}

	// solution : sum_of_'tree[i] - h' = m
	int min_len, max_len, mid_len;
	ull sum;
	max_len = *std::max_element(tree, tree + n);
	min_len = max_len - m;
	mid_len = (max_len + min_len) / 2;

	while (min_len <= max_len)
	{
		sum = 0;
		for (int i=0;i<n;++i) {
			if (tree[i] > mid_len)
				sum += tree[i] - mid_len;
		}
		if (sum < m)
			max_len = mid_len - 1;
		else
			min_len = mid_len + 1;
		mid_len = (max_len + min_len) / 2;
	} 

	std::cout << mid_len << '\n';
	return 0;
}