// SWEA
// 1209 [S/W 문제해결 기본] 2일차 - Sum

#include <iostream>

using namespace std;

int	arr[100][100];

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
	freopen("input.txt", "r", stdin);
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= 10; ++test_case)
	{
		// input
		cin>>T;
		
		for (int i=0;i<100;++i)
			for (int j=0;j<100;++j)
				cin >> arr[i][j];
		
		// solution
		int	ans(0);
		int	c_max(0), r_max(0), cc_max(0), c1_sum(0), c2_sum(0);
		for (int i=0;i<100;++i) {
			int	c_sum(0), r_sum(0);
			for (int j=0;j<100;++j) {
				c_sum += arr[j][i];
				r_sum += arr[i][j];
			}
			c1_sum += arr[i][i];
			c2_sum += arr[i][99-i];
			c_max = max(c_max, c_sum);
			r_max = max(r_max, r_sum);
		}
		cc_max = max(c1_sum, c2_sum);
		ans = max(c_max, r_max);
		ans = max(ans, cc_max);
		
		// output
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}