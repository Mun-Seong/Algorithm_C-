#include <iostream>

using namespace std;

bool board[101][101] = {0, };
bool vis[101][101] = {0, };
int xx[4] = {1, -1, 0, 0};
int yy[4] = {0, 0, 1, -1};
int n, m, k;

int dfs(int x, int y)
{
	int ret = 1;
	vis[x][y] =true;
	for (int i=0;i<4;i++)
	{
		int cx = x + xx[i];
		int cy = y + yy[i];
		if (cx <= 0 || cx > n || cy <= 0 || cy > m)
			continue;
		if (board[cx][cy] == true && vis[cx][cy] == false)
			ret += dfs(cx, cy);
	}
	return ret;
}

int main()
{
	int max = -1;
	int temp = 0;
	cin >> n >> m >> k;
	for (int i=0;i<k;i++)
	{
		int x, y;
		cin >> x >> y;
		board[x][y] = true;
	}
	for (int i=1;i<=n;i++)
	{	
		for(int j=1;j<=m;j++)
		{
			if (board[i][j] == true && vis[i][j] == false)
			{	
				temp = dfs(i, j);
				if (temp > max)
					max =temp;
			}
		}
	}
	cout << max;
}

