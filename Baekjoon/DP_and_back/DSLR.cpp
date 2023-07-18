// Baekjoon
// 9019 DSLR

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

bool	vis[10000];
int		dp[10000];
char	save[10000];

int	cal_D(int &i) { return ((i * 2) % 10000); }
int	cal_S(int &i) { if (i == 0) return (9999); else return (i - 1);}
int	cal_L(int &i) { return (((i % 1000) * 10) + (i / 1000)); } 
int	cal_R(int &i) { return (((i % 10) * 1000) + (i / 10)); }

int	t;

int	main()
{
	// init
	int	(*funcs[4])(int &) = {cal_D, cal_S, cal_L, cal_R};
	const char	cmd_char[5] = "DSLR";
	
	// input
	std::cin >> t;
	for (int tt=0;tt<t;++tt) {
		int	a, b;
		std::cin >> a >> b;

		// init
		memset((void *)dp, 0, sizeof(dp));
		memset((void *)vis, 0, sizeof(vis));
		memset((void *)save, 0, sizeof(save));
		// bfs
		bool	is_find = false;
		int		cal_num(0);
		std::queue<int>	q;
		q.push(a);
		vis[a] = true;
		save[a] = 'X';
		while (!q.empty()) {
			int	num = q.front(); q.pop();
			for (int i=0;i<4;++i) {
				cal_num = funcs[i](num);
				if (vis[cal_num])
					continue ;
				q.push(cal_num);
				vis[cal_num] = true;
				dp[cal_num] = num;
				save[cal_num] = cmd_char[i];
				if (cal_num == b) {
					is_find = true;
					break ;
				}
			}
			if (is_find)
				break ;
		}
		std::string	ans;
		// print and reverse
		while (save[cal_num] != 'X') {
			ans += save[cal_num];
			cal_num = dp[cal_num];
		}
		std::reverse(ans.begin(), ans.end());
		std::cout << ans << '\n';
	}

	return (0);
}