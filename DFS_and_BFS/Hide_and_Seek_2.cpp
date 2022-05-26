#include <iostream>
#include <queue>

using namespace	 std;

int n, k, mt, c;
bool vis[200001];

void bfs()
{
	queue<pair<int, int>> q;
	q.push({n, 0});
	vis[n] = true;
	while (!q.empty())
	{
		int f = q.front().first;
		int s = q.front().second;
		q.pop();
		vis[f] = true;
		if (c && f == k && mt == s)
			c++;
		if (!c && f == k)
		{
			mt = s;
			c++;
		}
		if (f * 2 <= 100000 && !vis[f * 2])
			q.push({f*2, s+1});
		if (f + 1 <= 100000 && !vis[f + 1])
			q.push({f+1, s+1});
		if (f - 1 >= 0 && !vis[f - 1])
			q.push({f-1, s+1});
	}
}

int main()
{
	cin >> n >> k;
	bfs();
	cout << mt << '\n' << c;
}