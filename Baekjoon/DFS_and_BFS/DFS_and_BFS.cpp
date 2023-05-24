#include <iostream>
#include <queue>
using namespace std;

int n, m, v;
bool d_vis[1001] = { 0, };
bool b_vis[1001] = { 0, };
int map[1001][1001];
queue<int> q;

void dfs(int v)
{
	d_vis[v] = true;
	cout << v << ' ';
	for (int i = 1; i <= n; i++)
	{
		if (map[v][i] == 1 && d_vis[i] == false)
			dfs(i);
	}
}

void bfs(int v)
{
	b_vis[v] = true;
	q.push(v);
	cout << v << ' ';
	
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (map[v][i] == 1 && b_vis[i] == false)
			{
				q.push(i);
				b_vis[i] = true;
				cout << i << ' ';
			}
		}
	}
}

int main()
{
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	dfs(v);
	cout << '\n';
	bfs(v);
	return (0);
}