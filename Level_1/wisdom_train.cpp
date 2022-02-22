#include <iostream>

using namespace std;

int main()
{
	int sta = 1;
	int num(0), in, out, max(0);
	while (sta <= 10)
	{
		cin >> out >> in;
		num = num - out + in;
		if (max < num)
			max = num;
		sta++;
	}
	cout << max;
}