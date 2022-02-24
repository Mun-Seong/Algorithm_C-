#include <iostream>
#include <string>
using namespace std;

int n,k;
string *words;

int main()
{
	cin >> n >> k;
	words = new string[n];
	for (int i=0;i<n;i++)
		cin >> words[i];
	cout << words[0].substr(4, words[0].length()-8);
}