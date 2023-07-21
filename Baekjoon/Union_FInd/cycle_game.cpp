// Baekjoon
// 20040 사이클 게임

#include <iostream>

int	parent[500000];
int	n, m;

int find(int x) 
{
	if (parent[x] == x) // 배열 인덱스와 값이 같다면 해당 값 리턴
		return x;
	return parent[x] = find(parent[x]); // 배열의 값을 인덱스로 갖는 값 리턴
}

void	f_union(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)	return;
	parent[y] = x;
}

bool isUnion(int x, int y) { // 두 노드가 연결되어있는지 판별하는 함수
	x = find(x);
	y = find(y);
	if (x == y)
		return true;
	return false;
}

int	main()
{
	// input
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> n >> m;
	for (int i=0;i<n;++i)
		parent[i] = i;

	// solution
	int	ans(0);
	for (int i=1;i<=m;++i) {
		int x, y;
		std::cin >> x >> y;
		if (isUnion(x, y)) {
			ans = i;
			break ;
		}
		f_union(x, y);
	}
	std::cout << ans << '\n';
	
	return (0);
}