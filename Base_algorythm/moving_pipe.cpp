#include <iostream>

using namespace std;

int n;
int board[17][17];
int xx[3] = {0, 1, 1};
int yy[3] = {1, 1, 0};
int count;

bool ok(int x, int y, int dir)
{
	if (dir == 0)
	{
		for (int i = 0;i < 1;i++)
		{
			int nx = x + xx[i];
			int ny = y + yy[i];
			if (!(nx > 0 && nx <= n &&
			ny > 0 && ny <= n && board[nx][ny] == 0))
				return (false);
		}
	}
	else if (dir == 1)
	{
		for (int i = 0;i < 3;i++)
		{
			int nx = x + xx[i];
			int ny = y + yy[i];
			if (!(nx > 0 && nx <= n &&
			ny > 0 && ny <= n && board[nx][ny] == 0))
				return (false);
		}
	}
	else if (dir == 2)
	{
		for (int i = 2;i < 3;i++)
		{
			int nx = x + xx[i];
			int ny = y + yy[i];
			if (!(nx > 0 && nx <= n &&
			ny > 0 && ny <= n && board[nx][ny] == 0))
				return (false);
		}
	}
	return (true);
}

void dfs(int x, int y, int dir)
{
	if (x == n && y == n)
	{
		count++;
		return ;
	}
	if (dir == 0)
	{
		for (int i = 0; i < 2; i++)
		{
			if (ok(x, y, i))
				dfs(x + xx[i], y + yy[i], i);
		}
	}
	else if (dir == 1)
	{
		for (int i = 0; i < 3; i++)
		{
			if (ok(x, y, i))
				dfs(x + xx[i], y + yy[i], i);
		}
	}
	else if (dir == 2)
	{
		for (int i = 1; i < 3; i++)
		{
			if (ok(x, y, i))
				dfs(x + xx[i], y + yy[i], i);
		}
	}
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> board[i+1][j+1];
	dfs(1, 2, 0);

	cout << count;
}