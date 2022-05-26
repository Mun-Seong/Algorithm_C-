#include <iostream>
#include <queue>

using namespace	 std;

int n, k, mt(200001), c;
bool vis[200001];
int save[200001];

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
		if (f == k)
		{	
			mt = min(mt, s);
			
		if (f * 2 <= 100000 && !vis[f * 2])
		{	
			q.push({f*2, s+1});
			vis[f*2] = true;
			save[f*2] = f;
		}
		if (f + 1 <= 100000 && !vis[f + 1])
		{
			q.push({f+1, s+1});
			vis[f+1] = true;
			save[f+1] = f;
		}
		if (f - 1 >= 0 && !vis[f - 1])
		{	
			q.push({f-1, s+1});
			vis[f-1] = true;
			save[f-1] = f;
		}
	}
}

int main()
{
	cin >> n >> k;
	bfs();
	cout << mt;
}