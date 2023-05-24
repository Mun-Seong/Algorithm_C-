#include <iostream>
#include <vector>

using namespace std;

int	N;
int rank[50];
vector<pair<int, int>> v;

void	pair_compare()
{
	for (int i=0; i<N; ++i)
	{
		for (int j=0; j<N; ++j)
		{
			if (i == j)
				continue;
			if (v[i].first > v[j].first && v[i].second > v[j].second)
				::rank[j]++;
		}
	}
}

int main()
{
	int w, h;
	cin >> N;
	for (int i=0;i<N;++i)
	{
		cin >> w >> h;
		v.push_back({w, h});
	}
	pair_compare();
	for (int i=0;i<N;++i)
		cout << ::rank[i] + 1 << ' ';
	cout << endl;
}