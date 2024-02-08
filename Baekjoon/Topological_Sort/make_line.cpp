// Baekjoon
// 2252 줄 세우기

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int indegree[32001];
vector<int> nodes[100001];
queue<int> q;
int ans[32001];

int main()
{
	int n, m;
	int start, end;
	cin >> n >> m;
	for (int i=0;i<m;i++)
	{
		cin >> start >> end;
		nodes[start].push_back(end);
		indegree[end]++;
	}
	for (int i=1;i<=n;i++)
	{
		if (indegree[i] == 0)
			q.push(i);
	}
	for (int i=1;i<=n;i++)
	{
		int x = q.front();
		ans[i] = x;
		q.pop();
		for (int j=0;j<nodes[x].size();j++)
		{
			int y = nodes[x][j];
			indegree[y]--;
			if (indegree[y] == 0)
				q.push(y);
		}
	}
	for (int i=1;i<=n;i++)
	{
		cout << ans[i] << ' ';
	}
}