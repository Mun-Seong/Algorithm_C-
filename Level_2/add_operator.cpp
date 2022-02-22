#include <iostream>
using namespace std;

int	cal(int *nums, int oper[4], int i, int n, int pre_ans)
{
	int ret, pre, next;
	next = pre_ans;
	pre = nums[i];

	cout << pre << ' ' << ' ' << next << endl;
	switch (i)
	{
	case 0:
		ret = pre + next;
		break;
	case 1:
		ret = pre - next;
		break;
	case 2:
		ret = pre * next;
		break;
	case 3:
		if (pre < 0 && next > 0)
			ret = -1 * ((-1 * pre) / next);
		else if (pre > 0 && next < 0)
			ret = -1 * (pre / (-1 * next));
		else
			ret = pre / next;
		break;
	default:
		break;
	}
	cal(nums, oper, i--, n - 1, ret);
	cout << "ret : " << ret << ' ';
	return (ret);
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
	
	cout << cal(nums, oper, n-2, n - 1, nums[n-1]);
	delete[] nums;
}