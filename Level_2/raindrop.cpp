#include <iostream>
using namespace std;

int w,h, ans(0);
int *lens;
int lef, rig, piv;

int	find_piv(int start)
{
	lef = lens[start];
	while (start < w)
	{
		if (lens[start] > lef)
		{
			rig = lens[start];
			break;
		}
		start++;
	}
	if (start == w)
		rig = lens[w-1];
	if (lef >= rig) piv=rig;
	else piv = lef;
	return(piv);
}

void check_deep(int lef_i, int rig_i)
{
	for (int i=lef_i;i<rig_i;i++)
	{
		if ((piv - lens[i]) > 0)
			ans += (piv - lens[i]);
		cout << ans << ' ';
	}
	cout << endl;
}

int main()
{
	cin >> h >> w;
	lens = new int[w];
	for (int i=0;i<w;i++)
		cin >> lens[i];
	int l_i(0), r_i;
	r_i = find_piv(l_i);
	check_deep(l_i, r_i);

	cout << ans;
	delete[] lens;
}