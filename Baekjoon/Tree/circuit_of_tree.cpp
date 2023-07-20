// Baekjoon
// 2263 트리의 순회

#include <iostream>
#include <algorithm>
#include <vector>

int		n;
int		in[100001];
int		idx_in[100001];
int		post[100001];

void	get_pre(int is, int ie, int ps, int pe)
{
	if (is > ie || ps > pe)
		return ;
	
	int root_idx = idx_in[post[pe]];
	int	left_size = root_idx - is;
	int	right_size = ie - root_idx;
	std::cout << in[root_idx] << ' ';

	get_pre(is, root_idx - 1, ps, ps + left_size - 1);
	get_pre(root_idx + 1, ie, ps + left_size, pe - 1);
}


int	main()
{
	// input
	std::cin >> n;
	for (int i=0;i<n;++i) {
		std::cin >> in[i];
		idx_in[in[i]] = i;
	}
	for (int i=0;i<n;++i) {
		std::cin >> post[i];
	}

	// solution
	get_pre(0, n-1, 0, n-1);
	return (0);
}