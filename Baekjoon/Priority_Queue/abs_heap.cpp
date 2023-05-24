// Baekjoon
// 11286 절댓값 힙

#include <iostream>
#include <queue>
#include <cmath>

struct	cmp {
	bool	operator()(int a, int b)
	{
		if (abs(a) == abs(b))
			return (a > b);
		return (abs(a) > abs(b));
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	// input
	int							n;
	std::priority_queue<int, std::vector<int>, cmp>	pq;
	
	std::cin >> n;

	// solution
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