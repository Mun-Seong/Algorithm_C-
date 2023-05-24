#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n,k,ans(0);
bool alpha[26];
vector <string> words;

void	check_words()
{
	int res(0);
	for (int i = 0; i < n; i++)
	{
		bool c = true;
		for (int j = 0; j < words[i].length(); j++)
		{
			if (!alpha[words[i][j] - 'a'])
			{
				c = false;
				break;
			}
		}
		if (c)
			res++;
		
	}
	ans = max(ans, res);
	return ;
}

void	teach_char(int n_char, int idx)
{
	if (k == idx)
	{
		check_words();
		return ;
	}
	else
	{
		for (int i = n_char; i < 26; i++)
		{
			if (!alpha[i])
			{
				alpha[i] = true;
				teach_char(i, idx + 1);
				alpha[i] = false;
			}
		}
	}
}

void	init_alpha()
{
	alpha['a' - 'a'] = true;
	alpha['c' - 'a'] = true;
	alpha['i' - 'a'] = true;
	alpha['n' - 'a'] = true;
	alpha['t' - 'a'] = true;
	k -= 5;
}

int main()
{
	cin >> n >> k;

	if (k < 5) { cout << 0; return (0);}
	else if (k == 26) { cout << n; return (0);}

	init_alpha();
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		s.erase(s.begin(), s.begin() + 4);
		s.erase(s.end() - 4, s.end());
		words.push_back(s);
	}

	teach_char(0, 0);

	cout << ans;
	return (0);
}