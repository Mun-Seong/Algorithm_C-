#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int v, e;

struct	union_find_tree
{
	vector<int> parent;
	vector<int> rank;
	void	init(int uf_n)
	{
		parent.clear();
		rank.clear();
		for (int i=0;i<uf_n;i++)
		{
			parent.push_back(i);
			rank.push_back(0);
		}
	}

	int		uf_find(int now)
	{
		if (parent[now] == now) return (now);
		else
		{
			int t = uf_find(parent[now]);
			parent[now] = t;
			return (t);
		}
	}

	bool	same_set (int v1, int v2)
	{
		return (uf_find(v1) == uf_find(v2)) ;
	}

	void	uf_union(int v1, int v2)
	{
		v1 = uf_find(v1), v2 = uf_find(v2);
		if (v1 == v2) return ;
		if (rank[v1] < rank[v2]) swap(v1, v2);
		parent[v2] = v1;
		if (rank[v1] == rank[v2]) rank[v1]++;
	}
}uf;

struct edge
{
	int v1, v2, cost;
	bool operator < (const edge& e1) const{return cost < e1.cost;} 
};
vector<edge> es;

int kruskal(int kn)
{
	int ret(0);
	uf.init(kn+1);
	sort(es.begin(), es.end());
	for (auto now: es)
	{
		if (!uf.same_set(now.v1, now.v2))
		{
			ret += now.cost;
			uf.uf_union(now.v1, now.v2);
		}
	}
	return (ret);
}
int main()
{
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		struct edge te;
		cin >> te.v1 >> te.v2 >> te.cost;
		es.push_back(te);
	}

	cout << kruskal(v);
}