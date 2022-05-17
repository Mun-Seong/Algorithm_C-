#include <iostream>
#include <queue>

using namespace std;
queue<long long> q;
long long DP[10000010];
int n;

long long	searching_count()
{
	for (int i = 1; i<= 9 ; i++)
	{
		q.push(i);
		DP[i] = i;
	}
	if (0 <= n && n <= 10)
		return (n);
	int idx = 10;
	while (idx <= n && !q.empty())
	{
		long long num = q.front();
		q.pop();
		int last = num % 10;
		for (int i = 0; i < last; i++)
		{
			q.push(num * 10 + i);
			DP[idx++] = num * 10 + i;
		}
	}
	if (idx >= n && DP[n] != 0) return (DP[n]);
	else return (-1);
}

int main()
{
	cin >> n;
	cout << searching_count();
}