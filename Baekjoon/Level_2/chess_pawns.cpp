#include <iostream>

int pawn[6];
int pawn_ans[6] = {1, 1, 2, 2, 2, 8};

int main()
{
	for (int i=0;i<6;++i)
		std::cin >> pawn[i];
	 for (int i=0;i<6;++i)
	 	std::cout << pawn_ans[i] - pawn[i] << ' ';
}