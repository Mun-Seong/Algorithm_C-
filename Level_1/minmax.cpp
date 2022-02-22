#include <iostream>

using namespace std;

int main()
{
	int N;
	int min, max;
	int *nums;
	int idx = 0;
	
	cin >> N;
	nums = new int[N];
	while (idx < N)
	{
		cin >> nums[idx++];
	}
	idx = 0;
	min = max = nums[idx++];
	while (idx < N)
	{
		if (nums[idx] < min)
			min = nums[idx];
		if (nums[idx] > max)
			max = nums[idx];
		idx++;
	}
	cout << min << ' ' << max;
	delete[] nums;
}