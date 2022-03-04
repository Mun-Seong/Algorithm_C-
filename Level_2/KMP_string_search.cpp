#include <iostream>
#include <sting.h>

using namespace std;

int main()
{
	char s[1000001], p[1000001];

	cin >> s >> p;
	char *ptr = strstr(s, p);

	if(ptr == NULL)
		cout << 0;
	else
		cout << 1;
}