#include <iostream>
using namespace std;

int n, s;
int nums[100000];

int	subsum(int deep)
{
	for (int i=0;i<n;i++)
	{
		int res = 0;
		for (int j=0;j<deep;j++)
		{
			res += nums[i+j];
		}
		if (res >= s)
			return (n);
	}
	return (0);
}

int main()
{
	cin >> n >> s;
	for (int i=0;i<n;i++)
		cin >> nums[i];
	
	return (0);
}