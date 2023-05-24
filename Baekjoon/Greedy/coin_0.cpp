/**
 * Baekjun 11047
 * Greedy algorithm
*/

#include <iostream>

using namespace std;

int N, K;
int A[10];

int main(void)
{
	/** input */
	cin >> N >> K;
	for (int i=0;i<N;++i)
		cin >> A[i];
	/** solution */
	int answer(0);
	for (int i=N-1;i>=0;--i)
	{
		if (K < A[i])
			continue;
		while (K >= A[i])
		{
			K -= A[i];
			++answer;
		}
	}
	cout << answer << endl;
}
/**
g++ -std=c++11 coin_0.cpp -o coin_0.exe
*/