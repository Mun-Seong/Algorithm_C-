/**
 *골드바흐의 추측은 유명한 정수론의 미해결 문제로,
 *2보다 큰 모든 짝수는 
 *두 소수의 합으로 나타낼 수 있다는 것이다. 
 *이러한 수를 골드바흐 수라고 한다. 
 *또, 짝수를 두 소수의 합으로 나타내는 표현을 
 *그 수의 골드바흐 파티션이라고 한다. 
 *예를 들면, 4 = 2 + 2, 6 = 3 + 3, 8 = 3 + 5, 
 *10 = 5 + 5, 12 = 5 + 7, 14 = 3 + 11, 14 = 7 + 7이다. 
 *10000보다 작거나 같은 모든 짝수 n에 대한 
 *골드바흐 파티션은 존재한다. 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int	t;
vector<int> prime(1, 2);

bool isPrime(int num)
{
	for (int i = 2; i <= num / 2; ++i)
		if (num % i == 0) return false;
	return true;
}

void	make_sum_of_prime(int num)
{
	int half = num / 2;
	for (int i=0; i< half; ++i)
	{
		int temp = half - i;
		if (isPrime(temp) && isPrime(num- temp))
		{
			cout << temp << ' ' << num - temp << endl;
			return ;
		}
	}
}

int main()
{
	std::cin >> t;
	int nums[t];
	for(int i=0;i<t;++i)
		std::cin >> nums[i];
	for (int i=0;i<t;++i)
		make_sum_of_prime(nums[i]);
}