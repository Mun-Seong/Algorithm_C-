// Baekjoon
// 15652 N과 M(4)

#include <iostream>

int		n, m;
int		arr[9];
bool	vis[9];

void	dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i=0;i<m;++i)
			std::cout << arr[i] << ' ';
		std::cout << '\n';
		return;
	}
	for (int i=1;i<=n;++i)
	{
		if ((!cnt || arr[cnt-1] <= i))
		{
			arr[cnt] = i;
			dfs(cnt + 1);
		}
	}
}

int main()
{
	std::cin >> n >> m;
	dfs(0); 
}