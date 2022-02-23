#include <iostream>
using namespace std;

int m_max = -1000000001;
int m_min = 1000000001;
void	cal(int *nums, int oper[4], int n, int res, int idx)
{
	if (idx == n)
	{
		if (res > m_max)
			m_max = res;
		if (res < m_min)
			m_min = res;
		return;
	}
	for(int i = 0; i < 4; i++)
	{
		if (oper[i] > 0)
		{
			oper[i]--;
			if (i == 0)
				cal(nums, oper, n, res + nums[idx], idx+1);
			else if (i == 1)
				cal(nums, oper, n, res - nums[idx], idx+1);
			else if (i == 2)
				cal(nums, oper, n, res * nums[idx], idx+1);
			else
				cal(nums, oper, n, res / nums[idx], idx+1);
			oper[i]++;
		}
	}
	return;
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
	
	cal(nums, oper, n, nums[0], 1);
	cout << m_max << endl << m_min;
	delete[] nums;
}