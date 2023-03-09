// Baekjoon
// 2580 스도쿠

#include <iostream>

int input_board[9][9];
int board[9][9];
int empty(0);

bool	is_wrong(int i, int j, int val)
{
	int ys = i / 3;
	int xs = j / 3;
	for (int a=0;a<3;++a)
	{
		for (int b=0;b<3;++b)
		{
			int y = ys*3 + a;
			int x = xs*3 + b;
			if (!(y==i && x==j) && input_board[y][x] == val)
				return (true);
		}
	}
	for (int a=0;a<9;++a)
	{
		if (a != j && input_board[i][a] == val)
			return (true);
		if (a != i && input_board[a][j] == val)
			return (true);
	}
}

void	solution(int cnt)
{
	if (cnt = empty)
		return;
	for (int i=0;i<9;++i)
	{
		bool check = true;
		for (int j=0;j<cnt;++j)
		{
			if (!input_board[i][j])
			{
				for (int a=1;a<=9;++a)
				{
					input_board[i][j] = a;
					if (!is_wrong(i, j, a))
						solution(cnt+1);
				}
			}
		}
	}
}

int main()
{
	for (int i=0;i<9;++i)
	{
		for (int j=0;j<9;++j)
		{
			std::cin >> input_board[i][j];
			if (!input_board[i][j])
				empty++;
		}
	}
	solution(0);
	std::cout << '\n';
	for (int i=0;i<9;++i)
	{
		for (int j=0;j<9;++j)
			std::cout << input_board[i][j] << ' ';
		std::cout << '\n';
	}
}