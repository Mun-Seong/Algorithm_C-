#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;
stack<char> bar;
int ans(0), temp(1);

void	cal(string str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == '(')
			temp *= 2;
		else if (str[i] == '[')
			temp *= 3;
		else if (str[i] == ')')
		{
			if (str[i-1] == '(')
			{
				ans += temp;
				temp /= 2;
			}
			else
				temp /= 2;
		}
		else if (str[i] == ']')
		{
			if (str[i-1] == '[')
			{
				ans += temp;
				temp /= 3;
			}
			else
				temp /= 3;
		}
		i++;
	}
}

int main()
{
	int i = 0;
	cin >> str;
	while (str[i] != '\0')
	{
		if (str[i] == '(')
			bar.push(str[i]);
		else if (str[i] == '[')
			bar.push(str[i]);
		else if (!bar.empty() && str[i] == ')')
		{
			if (bar.top() == '(')
				bar.pop();
			else break;
		}
		else if (!bar.empty() && str[i] == ']')
		{
			if (bar.top() == '[')
			{
				bar.pop();
			}
			else break;
		}
		else
			break;
		i++;
	}
	if (!bar.empty())
		cout << '0';
	else
	{	
		cal(str);
		cout << ans*temp << endl;
	}
}