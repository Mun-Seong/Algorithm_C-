// Baekjoon
// 1976 여행 가자

#include <iostream>

int	parent[201];
int	plan[1001];
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
	// init
	for (int i=1;i<=n;++i)
		parent[i] = i;
	// solution
	for (int i=1;i<=n;++i) {
		for (int j=1;j<=n;++j) {
			int	tmp;
			std::cin >> tmp;
			if (tmp) f_union(i, j);
		}
	}
	bool	isClear = true;
	for (int i=0;i<m;++i) {
		std::cin >> plan[i];
		if (i == 0)
			continue ;
		if (isUnion(plan[i], plan[i-1]) == false) {
			std::cout << "NO\n";
			isClear = false;
			break ;
		}
	}
	if (isClear)
		std::cout << "YES\n";

	return (0);
}