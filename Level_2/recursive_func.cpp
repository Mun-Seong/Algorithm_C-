#include <iostream>
#include <string>

using namespace std;

int T;

int recursion(string s, int l, int r, int *c){
	*c = *c + 1;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1, c);
}

int isPalindrome(string s, int *c){
    return recursion(s, 0, s.size()-1, c);
}

int main(){
	cin >> T;
	string	s[T];
	int		c[T] = {0, };
	for (int i=0; i<T; ++i)
		cin >> s[i];
	for (int i=0; i<T; ++i)
	{
		cout << isPalindrome(s[i], &c[i]);
		cout << c[i] << endl;
	}
}