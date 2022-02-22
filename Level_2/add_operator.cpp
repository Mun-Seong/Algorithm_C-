#include <iostream>
using namespace std;

int	cal(int *nums, int oper[4], int n)
{
	int idx, ret;
	ret = nums[n];
	if (n == 0)
		return (ret);
	for (int i=0;i<n;i++)
	{
		ret = nums[n];
		idx = i;
		while (oper[idx] == 0)
			idx++;
		if (idx > 3)
		{
			cout << "error" << endl;
			return (ret);
		}
		oper[idx]--;
		cout << ret << ' ' << idx << endl;
		switch (idx)
		{
		case 0:
			ret = cal(nums, oper, n - 1) + ret;
			break;
		case 1:
			ret = cal(nums, oper, n - 1) - ret;
			break;
		case 2:
			ret = cal(nums, oper, n - 1) * ret;
			break;
		case 3:
			if (ret < 0)
				ret = (cal(nums, oper, n - 1) / (ret * -1)) * -1;
			else
				ret = cal(nums, oper, n - 1) / ret;
			break;
		default:
			break;
		}
		oper[idx]++;
		cout << "ret : " << ret << ' ';
	}
	return ret;
}

int main()
{
	int n, oper[4], *nums;
	
	cin >> n;
	nums = new int[n];
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	for (int i = 0; i < 4; i++)
		cin >> oper[i];
	
	cout << cal(nums, oper, n - 1);
	delete[] nums;
}