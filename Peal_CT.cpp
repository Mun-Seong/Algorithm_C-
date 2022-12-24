#include <iostream>
using namespace std;

class Base
{
public:
	virtual void foo() { cout << "B_foo\n"; }
	void boo() { cout << "B_boo\n"; }
};

class D : public Base
{
public:
	virtual void foo() { cout << "D_foo\n"; }
	void boo() { cout << "D_boo\n"; }
};

int too(int n)
{
	return (too(n+1));
}

int main()
{
	/**
	 * D d;
	 * Base *b = static_cast<Base *>(&d);
	 * 
	 * d.foo();
	 * b->foo();
	 * 
	 * d.boo();
	 * b->boo();
	 * 
	 * result
	 * 1.D_foo 2.D_foo 3.D_foo 4.B_foo 
	*/
	
	/**
	 * int a = too(10000);
	 * cout << a << endl;
	 * 
	 * result
	 * stack overflow
	 */

	return (0);
}