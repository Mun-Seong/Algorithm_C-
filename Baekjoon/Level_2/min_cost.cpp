#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9

int n, m, ans;
vector<pair<int ,int>> arr[1000];
int dist[1000];

void	min_cost(int s)
{
	priority_queue<pair<int, int>> pq;

	pq.push({0,s-1});
	dist[s-1] = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;

		pq.pop();
		if (dist[here] < cost) continue;
		for (int i = 0; i < arr[here].size(); i++)
		{
			int next = arr[here][i].first;
			int nextcost = arr[here][i].second;

			if (dist[next] > dist[here] + nextcost)
			{
				dist[next] = dist[here] + nextcost;
				pq.push({-dist[next], next});
			}
		}
	}
}

int main()
{
	cin >> n;
	cin >> m;
	int s, e, v;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e >> v;
		arr[s-1].push_back({e-1, v});
	}
	cin >> s >> e;
	fill_n(dist, 1000, INF);
	min_cost(s);
	cout << dist[e-1];
}