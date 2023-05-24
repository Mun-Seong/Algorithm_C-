#include <iostream>

using namespace std;

int n, s, ans(1000001);
int nums[100000];

void	subsum()
{
	int start(0), end(0), temp(0);
	while (end <= n)
	{
		if (temp >= s)
		{	
			if (ans > (end - start))
				ans = end - start;
			temp -= nums[start++];
		}
		else if (temp < s)
			temp += nums[end++];
	}
}

int main()
{
	cin >> n >> s;
	for (int i=0;i<n;i++)
		cin >> nums[i];
	subsum();
	if (ans == 1000001) cout << 0;
	else cout << ans;
	return (0);
}