// Baekjoon
// 1927 최소 힙

#include <iostream>
#include <queue>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	// input
	int							n;
	std::priority_queue<int, std::vector<int>, std::greater<int>>	pq;
	
	std::cin >> n;
	int	t;
	for (int i=0;i<n;++i) {
		std::cin >> t;
		if (t == 0) {
			if (pq.empty())
				std::cout << "0\n";
			else {
				std::cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
			pq.push(t);
	}

	return (0);
}