// Baekjoon
// 1991 트리 순회

#include <iostream>
#include <algorithm>
#include <vector>

int		n;
int		tree[26][2];
char	alpha[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void	preorder(int s)
{
	if (s == -1)
		return ;
	std::cout << alpha[s];
	preorder(tree[s][0]);
	preorder(tree[s][1]);
}
void	inorder(int s)
{
	if (s == -1)
		return ;
	inorder(tree[s][0]);
	std::cout << alpha[s];
	inorder(tree[s][1]);
}
void	postorder(int s)
{
	if (s == -1)
		return ;
	postorder(tree[s][0]);
	postorder(tree[s][1]);
	std::cout << alpha[s];
}

int	main()
{
	// input
	std::cin >> n;
	for (int i=0;i<n;++i) {
		char	p, l, r;
		std::cin >> p >> l >> r;
		tree[p-'A'][0] = l != '.' ? l-'A' : -1;
		tree[p-'A'][1] = r != '.' ? r-'A' : -1;
	}

	// solution
	preorder(0);
	std::cout << '\n';
	inorder(0);
	std::cout << '\n';
	postorder(0);
	std::cout << '\n';

	return (0);
}