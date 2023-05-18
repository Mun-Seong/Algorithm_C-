// SWEA
// 1926 간단한 369게임

#include <iostream>
#include <algorithm>

using namespace std;

int	n;

int	check(int i)
{
	int mod = i, div = i, ret(0);
	while (div) {
		mod = div % 10;
		div = div / 10;
		if (mod != 0 && mod % 3 == 0)
			ret++;
	}
	return (ret);
}

int main(int argc, char** argv)
{
	cin >> n;
	for (int i=1;i<=n;++i) {
		int	clap = check(i);
		if (clap) {
			while (clap--)
				cout << '-';
		}
		else
			cout << i;
		cout << ' ';
	}
	cout << endl;
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}