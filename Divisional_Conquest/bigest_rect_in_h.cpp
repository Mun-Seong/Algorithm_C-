// Baekjoon
// 6549 히스토그램에서 가장 큰 직사각형

#include <iostream>
#include <vector>
#include <cstring>

long long			arr[100002];
std::vector<int>	v;

int main()
{
	int n;
	long long ret(0);
	while (1)
	{
		// input 
		std::cin >> n;
		if (n == 0)
			break ;
		for (int i=1;i<=n;++i)
			std::cin >> arr[i];
		
		// solution
		v.push_back(0);
		for (int i=1;i<=n+1;++i)
		{
			while (!v.empty() && arr[v.back()] > arr[i])
			{
				int c = v.back();
				v.pop_back();
				ret = std::max(ret, arr[c] * (i - v.back() - 1));
			}
			v.push_back(i);
		}
		std::cout << ret << '\n';
		v.clear();
		ret = 0;
		memset(arr, 0, 100000);
	}
	return (0);
}