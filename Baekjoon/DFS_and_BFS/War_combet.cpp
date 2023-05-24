#include <iostream>

using namespace std;

int n, m, w, b;
char board[101][101];
bool vis[101][101] = {0, };
int xx[4] = {-1, 1, 0, 0};
int yy[4] = {0, 0, 1, -1};

int dfs(int x, int y)
{
	char t = board[x][y];
	int ret = 1;
	vis[x][y] = true;
	for (int i=0;i<4;i++)
	{
		int cx = x + xx[i];
		int cy = y + yy[i];
		if (0 <= cx && cx < n && 0 <= cy && cy < m)
		{
			if (board[cx][cy] == t && vis[cx][cy]== false)
				ret += dfs(cx, cy);
		}
	}
	return ret;
}

int main()
{
	cin >> m >> n;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			cin >> board[i][j];

	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		{
			if (vis[i][j]==true)
				continue;
			int sum = dfs(i, j);
			if (board[i][j] == 'B')
				b += sum * sum;
			else
				w += sum * sum;
		}
	cout << w << ' ' << b;
}