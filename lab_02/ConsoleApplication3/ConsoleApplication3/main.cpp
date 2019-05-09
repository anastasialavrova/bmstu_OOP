#include "SokSet.h"
#include <iostream>

using namespace sset;

int main()
{
	try
	{
		sset::Set<int> a, d, e;
		int b[2] = { 0, 1 };
		a = sset::Set<int>(2, 0, 1);

		int c[3] = { 3, 2, 1 };
		d = sset::Set<int>(c, 3);

		e = sset::Set<int>();
		e = d;
		e ^= a;
		cout << a << e << d;
		e += a;
		cout << a << e << d;
		e -= a;
		cout << a << e << d;
		e *= a;
		cout << a << e << d;

		char *s1 = e.in_set(0) ? "Yes\n" : "No\n";
		char *s2 = e.in_set(1) ? "Yes\n" : "No\n";
		char *s3 = e.in_set(2) ? "Yes\n" : "No\n";
		char *s4 = e.in_set(3) ? "Yes\n" : "No\n";

		if (e.is_empty())
			cout << "Empty!\n";
		else
			cout << "Not empty!\n" << s1 << s2 << s3 << s4;
	}
	catch (set_memory_error& error)
	{
		cout << error.what();
	}

	system("pause");

	return 0;
}
