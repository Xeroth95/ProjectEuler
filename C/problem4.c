#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef unsigned long ulong;

ulong reverse(ulong n);
bool is_palindrom(ulong n);
ulong get_greatest_palin(short digits);

int main(int argc, char *argv[])
{
	ulong answer = get_greatest_palin(3);

	printf("The largest palindrome made from the product of two %d-digit"
	       "numbers is: %lu\n", 3, answer);
	return 0;
}

ulong reverse(ulong n)
{
	ulong rev = 0;
	while ( n != 0 )
	{
		rev *= 10;
		rev += n%10;
		n = n/10;
	}
	return rev;
}

bool is_palindrom(ulong n)
{
	return (n == reverse(n));
}

ulong get_greatest_palin(short digits)
{
	ulong i, j;
	ulong largest = 0;
	for (i = 100; i < 999; ++i)
	{
		for (j = i; j < 999; ++j)
		{
			ulong cur = i * j;
			if (cur > largest && is_palindrom(cur))
				largest = cur;
		}
	}
	return largest;
}
