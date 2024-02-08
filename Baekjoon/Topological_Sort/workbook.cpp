// Baekjoon
// 1766 문제집

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int						n, m;
vector<int>				res;

void	topological_sort(vector<vector<int>> &graph, vector<int> &indegree)
{
	queue<int>	q;

	for (int i=1;i<=n;++i)
		if (indegree[i] == 0)	{ q.push(i);	break; }

	for (int i=0;i<n;++i) {
		if (q.empty())	return ;
		int	cur  = q.front();	q.pop();
		res.push_back(cur);
		indegree[cur]--;

		for (auto a : graph[cur])
			indegree[a]--;
		for (int i=1;i<=n;++i)
			if (indegree[i] == 0)	{ q.push(i);	break; }
	}
	return ;
}

int	main()
{
	// input
	cin >> n >> m;

	// solution
	vector<vector<int>>	graph(n + 1);
	vector<int>			indegree(n + 1, 0);

	for (int i=0;i<m;++i) {
		int	tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		graph[tmp1].push_back(tmp2);
		indegree[tmp2]++;
	}

	topological_sort(graph, indegree);

	for (int i : res)	cout << i << ' ';
	cout << '\n';

	return (0);
}