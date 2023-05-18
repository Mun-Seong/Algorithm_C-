// SWEA
// 2814 최장 경로

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int				n, m, ans;
bool			vis[11];
bool			graph[11][11];

void	dfs(int idx, int cnt)
{
	if (cnt > ans)
		ans = cnt;
	for (int i=1;i<=n;++i) {
		if (graph[idx][i] && !vis[i]) {
			vis[i] = true;
			dfs(i, cnt+1);
			vis[i] = false;
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		// init
		memset((void*)vis, 0, sizeof(vis));
		memset((void*)graph, 0, sizeof(graph));
		// input
		cin >> n >> m;
		for (int i=0;i<m;++i) {
			int s, e;
			cin >> s >> e;
			graph[s][e] = 1;
			graph[e][s] = 1;
		}

		// solution

		ans = 0;
		for (int i=1;i<=n;++i) {
			vis[i] = true;
			dfs(i, 1);
			vis[i] = false;
		}

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}