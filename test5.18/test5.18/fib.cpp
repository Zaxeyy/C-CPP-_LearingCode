#include"head.h"

int Fib(int n)
{
	if (n == 0)return 1;
	if (2 >= n)return n;
	int a = 1, b = 2,temp;
	while (-2+n--)
	{
		temp = b;
		b += a;
		a = temp;
	}
	return b;
}



 