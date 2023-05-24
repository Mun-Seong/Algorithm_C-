#include <iostream>
using namespace std;

int w,h,ans(0),piv;
int *lens;

int find_max_idx(int *ptr, int start, char po)
{
	int max_i(0), max_v(-1);
	if (po == 'r')
	{
		for (int i=start;i<w;i++)
		{
			if (max_v < ptr[i])
			{
				max_i = i;
				max_v = ptr[i];
			}
		}
	}
	else if (po == 'l')
	{
		for (int i=start;i>=0;i--)
		{
			if (max_v < ptr[i])
			{
				max_i = i;
				max_v = ptr[i];
			}
		}
	}
	return (max_i);
}

void check_deep(int lef_i, int rig_i)
{
	for (int i=lef_i;i<rig_i;i++)
	{
		if ((piv - lens[i]) > 0)
			ans += (piv - lens[i]);
	}
}

void	cal(int max_i)
{
	int l_i, r_i;
	int t = max_i;
	while (t != 0)
	{
		l_i = find_max_idx(lens, t-1, 'l');
		if (lens[l_i] <= lens[max_i]) piv = lens[l_i];
		else piv = lens[max_i];
		check_deep(l_i, t);
		t = l_i;
	}
	t = max_i;
	while (t != w-1)
	{
		r_i = find_max_idx(lens, t+1, 'r');
		if (lens[r_i] <= lens[max_i]) piv = lens[r_i];
		else piv = lens[max_i];
		check_deep(t, r_i);
		t = r_i;
	}
} 

int main()
{
	cin >> h >> w;
	lens = new int[w];
	for (int i=0;i<w;i++)
		cin >> lens[i];
	int left_i(0), right_i(0);
	int max_i = find_max_idx(lens, 0, 'r');
	cal(max_i);
	cout << ans;
	delete[] lens;
}