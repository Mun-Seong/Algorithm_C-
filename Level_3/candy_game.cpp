#include <iostream>
#include <algorithm>

using namespace std;

int maxcount(0);

void	check_row(char board[51][51], int n)
{
	for (int i=0;i<n;i++)
	{
		int count = 1;
		for (int j=0;j<n;j++)
		{
			if (board[j][i] == board[j+1][i])
				count++;
			else
			{
				if (count > maxcount)
					maxcount = count;
				count = 1;
			}
		}
	}
}

void	check_col(char board[51][51], int n)
{
	for (int i=0;i<n;i++)
	{
		int count = 1;
		for (int j=0;j<n;j++)
		{
			if (board[i][j] == board[i][j+1])
				count++;
			else
			{
				if (count > maxcount)
					maxcount = count;
				count = 1;
			}
		}
	}
}

int main()
{
	char board[51][51];
	int n;
	cin >> n;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
			cin >> board[i][j];
	}

	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n - 1;j++)
		{
			swap(board[i][j], board[i][j+1]);

			check_row(board, n);
			check_col(board, n);

			swap(board[i][j+1], board[i][j]);

			swap(board[j][i], board[j+1][i]);

			check_row(board, n);
			check_col(board, n);

			swap(board[j+1][i], board[j][i]);
		}
	}
	cout << maxcount;
}