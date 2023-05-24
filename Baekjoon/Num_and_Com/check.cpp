// Baekjoon
// 2981 검문

#include <iostream>
#include <vector>
#include <algorithm>

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
	std::vector<int> ans;
	for (int i=0;i<N;++i)
		std::cin >> arr[i];
	std::sort(arr, arr + N);
	
	// solution
	int tmp_mod = arr[1] - arr[0];
	for (int i=2;i<N;++i)
		tmp_mod = gcd(tmp_mod, arr[i] - arr[i-1]);
	for (int i=1; i*i <= tmp_mod; ++i)
	{
		if (tmp_mod % i == 0)
		{
			ans.push_back(i);
			if (i != tmp_mod / i)
				ans.push_back(tmp_mod / i);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i=1;i<ans.size();++i)
		std::cout << ans[i] << ' ';
	std::cout << '\n';
}