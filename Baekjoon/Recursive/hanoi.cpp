#include <iostream>

using namespace std;

int cnt = 0;

void hanoi(int n, int s, int m, int e)
{
	if (n == 1)
		cout << s << ' ' << e << '\n';
	else
	{
		hanoi(n-1, s, e, m);
		cout << s << ' ' << e << '\n';
		hanoi(n-1, m, s, e);
	}
}

int cnt_hanoi(int n)
{
	if (n == 1)
		return (1);
	return ((cnt_hanoi(n-1) * 2)+ 1);
}

int main()
{
	int N ,cnt(0);
	cin >> N;
	cnt = cnt_hanoi(N);
	cout << cnt << endl;
	hanoi(N, 1, 2, 3);
}	