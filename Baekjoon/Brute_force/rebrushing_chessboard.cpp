#include <iostream>
#include <string>
#include <vector>

using namespace std;

int	N, M;
string board[50];

string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

int worng_cnt(int n, int m, bool check)
{
	int cnt = 0;
	for (int i=0; i<8; ++i)
	{
		for (int j=0; j<8; ++j)
		{
			if (check)
			{
				if (board[n+i][m+j] != WB[i][j])
					cnt++;
			}
			else
			{
				if (board[n+i][m+j] != BW[i][j])
					cnt++;
			}
		}
	}
	return (cnt);
}

int main()
{
	cin >> N >> M;
	int save;
	int min_val = 999999;
	for (int i=0;i<N;++i)
		cin >> board[i];
	for (int i=0; i+8<=N; ++i)
	{
		for (int j=0; j+8<=M; ++j)
		{
			save = min(worng_cnt(i, j, 1), worng_cnt(i, j, 0));
			min_val = min(save, min_val);
		}
	}
	cout << min_val;
	return 0;
}