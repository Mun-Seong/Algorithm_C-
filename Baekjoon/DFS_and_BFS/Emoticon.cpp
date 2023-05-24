#include <iostream>
#include <queue>

using namespace std;

int n;
bool vis[2001][2001];

int bfs()
{
	queue<pair<pair<int,int>,int>> q;
	q.push({{1,0},0});
	vis[1][0] = true;

	while(!q.empty())
	{
		int f = q.front().first.first;
		int s = q.front().first.second;
		int t = q.front().second;
		q.pop();

		if (f == n) return s;
		if (f > 0 && f < 2001)
		{
			if (vis[f][f] == false)
			{
				vis[f][f] = true;
				q.push({{f,s+1}, f});
			}
			if (vis[f-1][t] == false)
			{
				vis[f-1][t] = true;
				q.push({{f-1,s+1}, t});
			}
		}
		if (t > 0 && f+t < 2001)
		{
			if (vis[f+t][t] == false)
			{
				vis[f+t][t] = true;
				q.push({{f+t,s+1},t});
			}
		}
	}
}

int main()
{
	cin >> n;
	cout << bfs();
}