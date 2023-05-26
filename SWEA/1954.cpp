// SWEA
// 1954 달팽이 숫자
#include<iostream>

using namespace std;

int	n;
int	arr[10][10];

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
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		// input
		cin >> n;

		// solution
		int	num = 1, i = 0, j = 0;
		int	dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
		int	dir_m[4] = {n-1, n-1, n-1, n-1};
		int	dir_n = 0, is(0), js(0), je(0), ie(0);
		//arr[i][j] = num++;
		while (num <= n * n) {
			arr[i][j] = num;
			//cout << i << ", " << j << " = " << num  << " dir :" << dir_n << '\n';
			switch (dir_n)
			{
			case 0:
				if (j == n - je - 1) {
					is++;
					dir_n = (dir_n + 1) % 4;
				}
				break;
			case 1:
				if (i == n - ie - 1) {
					je++;
					dir_n = (dir_n + 1) % 4;
				}
				/* code */
				break;
			case 2:
				if (j == js) {
					ie++;
					dir_n = (dir_n + 1) % 4;
				}
				/* code */
				break;
			case 3:
				if (i == is) {
					js++;
					dir_n = (dir_n + 1) % 4;
				}
				/* code */
				break;
			default:
				break;
			}
			i += dir[dir_n][0];
			j += dir[dir_n][1];
			num++;
		}


		// output
		cout << '#' << test_case << '\n';
		for (int i=0;i<n;++i) {
			for (int j=0;j<n;++j) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}