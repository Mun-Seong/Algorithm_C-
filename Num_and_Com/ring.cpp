// Baekjoon
// 3036 링

#include <iostream>

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return (a);
}

int main()
{
	int N;
	std::cin >> N;

	int arr[N];
	std::pair<int, int> ans[N-1];
	for (int i=0;i<N;++i)
		std::cin >> arr[i];
	
	// solution
	int tmp;
	for (int i=1;i<N;++i)
	{
		tmp = gcd(arr[0], arr[i]);
		ans[i-1].first = arr[0] / tmp;
		ans[i-1].second = arr[i] / tmp;
	}
	for (int i=0;i<N-1;++i)
		std::cout << ans[i].first << '/' << ans[i].second << '\n';
	return 0; 
}