#include <iostream>
using namespace std;

int main()
{
	int heights[9];
	int idx(0), sum(0);
	int tmp;
	bool end = false;

	while (idx < 9)
		cin >> heights[idx++];
	idx = 0;
	while (idx < 9)
		sum = sum + heights[idx++];
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (heights[i] + heights[j] == sum - 100)
			{
				heights[i] = heights[j] = 0;
				end = true;
				break;
			}
		}
		if (end)
			break;
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (heights[i] > heights[j])
			{
				tmp = heights[j];
				heights[j] = heights[i];
				heights[i] = tmp;
			}
		}
	}
	for (int i = 2; i < 9; i++)
		cout << heights[i] << endl;
}