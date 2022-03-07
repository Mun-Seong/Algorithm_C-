#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int ad[26][26];
bool check[26][26];
int h_count;
int cx[4] = {1,-1,0,0};
int cy[4] = {0,0,1,-1};

vector<int> v;

void	DFS(int x, int y)
{
	h_count++;
	check[x][y] = true;
	for (int i=0;i<4;i++)
	{
		int nx = x + cx[i];
		int ny = y + cy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n)	continue;
		if (ad[nx][ny] && check[nx][ny] == false)
			DFS(nx, ny);
	}
}

int main()
{
	cin >> n;
	for (int i=0;i<n;i++)
	{
		string t;
		cin >> t;
		for (int j=0;j<n;j++)
			ad[i][j] = t[j] - '0';
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (ad[i][j] && check[i][j] == false)
			{
				h_count = 0;
				DFS(i, j);
				v.push_back(h_count);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (auto i:v) cout << i << endl;
}