#include <iostream>
using namespace std;

int n,k,ans(0);
int *nums;
int mul[100];
int prio[100];

int check_priority()
{
	int min_idx(0), min_val(101);
	for (int i=0;i<n;i++)
	{
		if (prio[mul[i]] < min_val)
		{
			min_idx = i;
			min_val = prio[mul[i]];
		}
	}
	return (min_idx);
}

void scheduling()
{
	bool flag(false);
	int c_idx(0);
	for (int i=n;i<k;i++)
	{
		flag = false;
		for (int j=0;j<n;j++)
		{
			if (nums[i] == mul[j])
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{	
			c_idx = check_priority();
			mul[c_idx] = nums[i];
			cout << "\nafter : ";
			for (int i=0;i<n;i++)
				cout << mul[i] << ' ';
			cout << ": " << nums[i];
			ans++;
		}
		prio[nums[i]]--;
	}
}

int main()
{
	cin >> n >> k;
	nums = new int[k];
	for (int i=0;i<k;i++)
		cin >> nums[i];
	for (int i=0;i<k;i++)
		prio[nums[i]]++;
	for (int i=0;i<n;i++)
	{
		mul[i] = nums[i];
		prio[nums[i]]--;
	}

	scheduling();
	cout << ans;
	delete[] nums;
}