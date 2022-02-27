#include <iostream>
using namespace std;

int n,k,ans(0);
int *nums;
int mul[100];

/*
컨디션 3개
1)이미 콘센트에 있는 경우
2)콘센트에 빈 자리가 있는 경우 
3)콘센트에 빈 자리가 없는 경우
1), 2)번의 경우에는 콘센트를 빼지 않음

3)번의 경우에 어떤 콘센트를 빼야하나
 i )가장 나중에 다시 사용되거나
 ii)앞으로 사용되지 않는 기기
*/
void	scheduling()
{
	for (int i = 0; i < k; i++)
	{
		bool flag(false);

		for (int j = 0; j < n; j++)
		{
			if (mul[j] == nums[i])
			{
				flag = true;
				break;
			}
		}
		if (flag)
			continue;
		//위는 경우 1)일 때
		for (int j = 0; j < n; j++)
		{
			if (mul[j] == 0)
			{
				mul[j] = nums[i];
				flag = true;
				break;
			}
		}
		if (flag)
			continue;
		// 위의 경우 2)일 때
		int c_idx(-1), min_idx(-1);
		for (int j = 0; j < n; j++)
		{
			int lastidx(0);
			for (int a = i + 1; a < k; a++)
			{
				if (mul[j] == nums[a])
					break;
				lastidx++;
			}
			if (lastidx > min_idx)
			{
				c_idx = j;
				min_idx = lastidx;
			}
		}
		ans++;
		mul[c_idx] = nums[i];
	}
}

int main()
{
	cin >> n >> k;
	nums = new int[k];
	for (int i=0;i<k;i++)
		cin >> nums[i];
	scheduling();
	cout << ans;
	delete[] nums;
}