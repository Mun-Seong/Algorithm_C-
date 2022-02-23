#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;
stack<char> bar;
stack<bool> oper;
stack<int> nums;
int ans;

void	cal(int i)
{
	int a, b;
	if (i == 0)
		oper.push(true);
	while (!(oper.empty()))
	{
		a = nums.top();
		nums.pop();	
		b = nums.top();
		nums.pop();
		if (oper.top())
			ans = a * b;
		else
			ans = a + b;
		oper.pop();
		nums.push(ans);
	}
}
int main()
{
	char temp;
	int i = 0;
	cin >> str;
	while (str[i] != '\0')
	{
		if (str[i] == '(')
		{
			bar.push(str[i]);
			nums.push(2);
		}
		else if (str[i] == '[')
		{
			bar.push(str[i]);
			nums.push(3);
		}
		else if (!bar.empty() && str[i] == ')')
		{
			if (bar.top() == '(')
			{
				bar.pop();
				if (str[i+1] == '\0')
					cal(1);
				else if (str[i+1] == '[' || str[i+1] == '(')
					oper.push(false);
				else
					cal(0);
			}
			else break;
		}
		else if (!bar.empty() && str[i] == ']')
		{
			if (bar.top() == '[')
			{
				bar.pop();
				if (str[i+1] == '\0')
					cal(1);
				else if (str[i+1] == '[' || str[i+1] == '(')
					oper.push(false);
				else
					cal(0);
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
		cout << ans << endl;
}