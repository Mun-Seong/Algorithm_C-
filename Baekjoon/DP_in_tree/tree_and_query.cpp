// Baekjoon
// 15681 트리와 쿼리

#include <iostream>
#include <vector>

int					n, r, q;
std::vector<int>	vec[100001];
bool				vis[100001];
int					num[100001];


int	dfs(int node)
{
	if (num[node] != 0)	return (num[node]);

	vis[node] = true;
	int	ret = 1;
	for (auto a : vec[node]) {
		if (vis[a])	continue;
		ret += dfs(a);
	}
	num[node] = ret;
	return (ret);
}

int	main()
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); std::cout.tie(NULL);
	// input
	std::cin >> n >> r >> q;
	for (int i=0;i<n-1;++i) {
		int	u, v;
		std::cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	//solution
	num[r] = dfs(r);
	for (int i=0;i<q;++i) {
		int	sub_r;
		std::cin >> sub_r;
		std::cout << num[sub_r] << '\n'; 
	}

	return (0);
}