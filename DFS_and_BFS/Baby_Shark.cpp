#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool check[51][51];
int	board[51][51];
int n, m;
int xx[8] = {1, -1, 1, -1, 1, -1, 0, 0};
int yy[8] = {0, 0, 1, -1, -1, 1, 1, -1};

int bfs(int x, int y)
{
	memset(check, false, sizeof(check));
	queue<pair<pair<int,int>,int>> q;
	check[x][y] = true;
	q.push({{x, y}, 0});
	while (!q.empty())
	{
		x = q.front().first.first;
		y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (board[x][y]) return cnt;
		for (int i=0;i<8;i++)
		{
			int cx = x + xx[i];
			int cy = y + yy[i];
			if (0 < cx && cx <= n && 0 < cy && cy <= m && check[cx][cy] == false)
			{
				check[cx][cy] = true;
				q.push({{cx, cy}, cnt + 1});
			}
		}
	}
	return (99999);
}

int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> board[i][j];
	bfs();
}