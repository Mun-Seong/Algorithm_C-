#include <iostream>
using namespace std;

int	get_val(int n)
{
	int sum(0);
	for (int i = 1;;i++)
	{
		sum = sum + i;
		if (sum >= n)
			return (i);
	}
}

int main()
{
	int start, end, sum(0);
	cin >> start >> end;
	for (int i = start; i <= end; i++)
		sum = sum + get_val(i);
	cout << sum;
}
