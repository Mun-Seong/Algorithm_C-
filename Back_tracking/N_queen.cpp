// Baekjoon
// 9663 N-Queen

#include <iostream>

int		n, ans(0);
int		arr[15] = {0, };

bool	is_attack(int a, int b)
{
	return (arr[a] == arr[b]
		|| (a-b) == (arr[a] - arr[b])
		|| (a-b) == (arr[b] - arr[a]));
}

void	dfs(int cnt)
{
	if (cnt == n)
	{
		ans++;
		return;
	}
	for (int i=0;i<n;++i)
	{
		bool check = true;
		for (int j=0;j<cnt;++j)
		{
			arr[cnt] = i;
			if (is_attack(j ,cnt))
			{
				check = false;
				break;
			}
		}
		if (check)
			dfs(cnt+1);
	}
}

int main()
{
	std::cin >> n;
	for(int i=0;i<n;++i)
	{
		arr[0] = i;
		dfs(1);
	}
	std::cout << ans << std::endl;
}