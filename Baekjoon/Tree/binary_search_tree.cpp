// Baekjoon
// 5639 이진 검색 트리

#include <iostream>
#include <algorithm>

int	pre[10000];
int	tree[10000][2];

void	get_post(int s, int e)
{
	if (s >= e)
		return ;
	if (s == e - 1) {
		std::cout << pre[s] << '\n';
		return ;
	}
	int idx = s + 1;
	while (idx < e) {
		if (pre[s] < pre[idx])
			break ;	// root 보다 크면 right
		idx++;
	}
	get_post(s + 1, idx);
	get_post(idx, e);
	std::cout << pre[s] << '\n';
}

int	main()
{
	// input
	int	tmp;
	int	idx = 0;
	while (std::cin >> tmp)
		pre[idx++] = tmp;
	
	// solution
	get_post(0, idx);

	return (0);
}