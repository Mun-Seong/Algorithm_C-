#include <iostream>
#include <string>

using namespace std;

int N, M;
int arr[1001][1001];
bool vis[1001];

void	dfs(int s)
{
	vis[s] = true;
	for (int i=0;i<N;++i)
	{
		if (arr[s][i])
		{
			if (!vis[i])
				dfs(i);
		}
	}
}


int getConnectedComponent(int N)
{
	int ans(0);

	for(int i=0;i<N;++i)
	{
		if (vis[i])
			continue;
		dfs(i);
		ans++;
	}
	return (ans);
}

int main()
{
	int s, e;
	cin >> N >> M;
	for (int i=0;i<M;++i)
	{
		cin >> s >> e;
		arr[s-1][e-1] = 1;
		arr[e-1][s-1] = 1;
	}
	cout << getConnectedComponent(N) << endl;
}