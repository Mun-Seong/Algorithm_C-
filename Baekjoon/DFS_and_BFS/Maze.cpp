#include <iostream>
#include <queue>

bool vis[101][101];
char board[101][101];
int check[101][101];
int xx[4] = {1, -1, 0, 0};
int yy[4] = {0, 0, 1, -1};
int n, m;

using namespace std;

void bfs()
{
	vis[0][0] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int cx = x + xx[i];
			int cy = y + yy[i];
			if (0 <= cx && cx < n && 0 <= cy && cy < m)
			{
				if (board[cx][cy] == '1' && vis[cx][cy] == false)
				{
					check[cx][cy] = check[x][y] + 1;
					vis[cx][cy] = true;
					q.push(make_pair(cx, cy));
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			cin >> board[i][j];
	bfs();
	cout << check[n-1][m-1] + 1;
}