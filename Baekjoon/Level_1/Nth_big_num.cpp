#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	int *num_3rd;
	int nums[10];
	int idx_t, idx_3(0);
	
	cin >> T;
	num_3rd = new int[T];
	while (idx_3 < T)
	{
		idx_t = 0;
		while (idx_t < 10)
		{
			cin >> nums[idx_t++];
		}
		sort(nums, nums + 10);
		num_3rd[idx_3++] = nums[7];
	}
	idx_3 = 0;
	while (idx_3 < T)
		cout << num_3rd[idx_3++] << endl;
	delete[] num_3rd;
}