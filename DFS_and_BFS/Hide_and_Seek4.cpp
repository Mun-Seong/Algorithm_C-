#include <iostream>
#include <queue>
#include <vector>

#define MAX 1000001

using namespace	 std;

int n, k, mt(MAX), c;
bool vis[MAX];
int save[MAX];

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
		}
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
	if (n == k)
	{
		cout << 0 << '\n';
		cout << n;
		return (0);
	}
	bfs();
	cout << mt << '\n';

	int x = k;
	vector<int> v;
	v.push_back(k);
	while (save[x] != n)
	{
		v.push_back(save[x]);
		x = save[x];
	}
	v.push_back(save[x]);
	for(vector<int>::iterator i=v.end() - 1;i>=v.begin();i--)
		cout << *i << ' ';	
}