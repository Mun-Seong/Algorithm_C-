#include <iostream>
#include <queue>

using namespace std;

bool board[51][51];
int	check[51][51];
int n, m;
int xx[8] = {1, -1, 1, -1, 1, -1, 0, 0};
int yy[8] = {0, 0, 1, -1, -1, 1, 1, -1};

void bfs()
{
	queue<int,int> q;
	
}

int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> board[i][j];
	bfs();
}