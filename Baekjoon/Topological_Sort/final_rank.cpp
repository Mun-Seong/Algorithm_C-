// Baekjoon
// 3665 최종 순위

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int						t, n, m;
vector<int>				res;

short	topological_sort(vector<vector<int>> &graph, vector<int> &indegree)
{
	queue<int>	q;
	bool		swap = false;

	res.clear();
	for (int i=1;i<=n;++i)
		if (indegree[i] == 0)	q.push(i);

	for (int i=0;i<n;++i) {
		if (q.size() > 1)	return (-1);
		if (q.empty())		return (1);
		int	cur  = q.front();	q.pop();
		res.push_back(cur);

		for (auto a : graph[cur]) {
			if (--indegree[a] == 0)	q.push(a);
		}
	}
	return (0);
}


int	main()
{
	// input
	cin >> t;
	for (int tt=0;tt<t;++tt) {
		cin >> n;
		// init
		vector<vector<int>> graph(n + 1);	
		vector<int> 		indegree(n + 1, 0);
		vector<int>			prev_rank;
		for (auto a : graph)	a.clear();

		// input
		for (int i=0;i<n;++i) {
			int	tmp;
			cin >> tmp;
			prev_rank.push_back(tmp);
		}
		for (int i=0;i<n;++i) {
			for (int j=i+1;j<n;++j) {
				graph[prev_rank[i]].push_back(prev_rank[j]);
				indegree[prev_rank[j]]++;
			}
		}
		cin >> m;
		for (int i=0;i<m;++i) {
			int	tmp1, tmp2, top, bot;
			cin >> tmp1 >> tmp2;
			
			// solution
			auto	it = find(graph[tmp1].begin(), graph[tmp1].end(), tmp2);
			top = tmp1;	bot = tmp2;
			if (it == graph[tmp1].end()) {
				it = find(graph[tmp2].begin(), graph[tmp2].end(), tmp1);
				top = tmp2; bot = tmp1;
			}
			graph[top].erase(it);
			indegree[bot]--;
			graph[bot].push_back(top);
			indegree[top]++;
		}
		int ans = topological_sort(graph, indegree);
		switch (ans)
		{
		case 1:
			cout << "IMPOSSIBLE" << '\n';
			break;
		case -1:
			cout << '?' << '\n';
			break;
		
		default:
			for (int rank : res)	cout << rank << ' ';
			cout << '\n';
			break;
		}
	}

	return (0);
}