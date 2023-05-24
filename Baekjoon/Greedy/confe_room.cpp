/**
 * Baekjun 1931
 * Greedy algorithm
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return (a.first > b.first);
	return (a.second > b.second);
}

int main(void)
{
	/** input */
	cin >> N;
	for (int i=0;i<N;++i)
	{
		int f, s;
		cin >> f >> s;
		v.push_back(make_pair(f, s));
	}
	/** solution */
	sort(v.begin(), v.end(), compare);
	int answer(0), end(0);
	pair<int ,int> tmp;
	while(v.size() > 0)
	{
		tmp = v.back();
		if (end <= tmp.first) {
			answer++;
			end = tmp.second;
		}
		v.pop_back();
	}
	
	cout << answer << endl;
}
/**
g++ -std=c++11 confe_room.cpp -o confe_room.exe
*/