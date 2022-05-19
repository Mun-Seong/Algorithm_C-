#include <iostream>
#include <queue>

using namespace std;

int n, l;
int mat[101][101] = {0, };
bool vis[101];
int ans = 0;

void bfs()
{
	queue<int> q;
	q.push(1);
	vis[1] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for(int i=1;i<=n;i++)
		{
			if(mat[cur][i] == 1 && vis[i] == false)
			{
				q.push(i);
				ans++;
			}
		}
	}
}

int main()
{
	cin >> n >> l;
	for(int i=0;i<l;i++)
	{
		int x, y;
		cin >> x >> y;
		mat[x][y] = 1;
		mat[y][x] = 1;
	}
	bfs();
	cout << ans;
}