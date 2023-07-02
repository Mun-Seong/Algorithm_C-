// Baekjoon
// 14003 가장 긴 증가하는 부분 수열 5

#include <iostream>
#include <algorithm>
#include <vector>

int	n;
int	seq[1000001];
int	dp[1000001];
std::vector<int>	v;

int	main()
{
	// input
	std::cin >> n;
	for (int i=1;i<=n;++i)
		std::cin >> seq[i];
	
	// solution

	int	res(0), max_idx(0);
	v.push_back(seq[1]);
	for (int i=2; i<=n; ++i)
	{
		if (v[res] < seq[i]) {
			v.push_back(seq[i]);
			dp[i] = ++res;
		}
		else {
			int pos = std::lower_bound(v.begin(), v.end(), seq[i]) - v.begin();
			v[pos] = seq[i];
			dp[i] = pos;
		}
	}

	/** LIS_4와 동일 */
	std::cout << res+1 << std::endl;
	std::vector<int>	ans;	
	for (int i=n;i>=0;--i) {
		if (dp[i] == res) {
			ans.push_back(seq[i]);
			res--;
		}
	}
	int	size = ans.size();
	for (int i=0;i<size;++i) {
		std::cout << ans.back() << ' ';
		ans.pop_back();
	}
	/** 거꾸로 출력 됨 수정 필요 */
	return (0);
}