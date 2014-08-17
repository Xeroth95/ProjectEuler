#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef unsigned long ulong;

short largest_pfaktor(short n);
bool is_prime(short n);
ulong get_cclm(short n);

int main(int argc, char *argv[])
{
	ulong answer = get_cclm(20);

	printf("The smallest number that can be divided by the numbers"
	       " 1 to %d is: %lu\n", 20, answer);

	return 0;
}

ulong get_cclm(short n)
{
	short arr[n];
	ulong ret = 1;

	short i;
	for (i = 0; i < n; ++i)
	{
		arr[i] = i+1;
	}
	
	i = 1;
	while (i <= n)
	{
		if (arr[i-1] == 1)
		{
			++i;
			continue;
		}
		short b = largest_pfaktor(arr[i-1]);
		ret *= b;
		short j;
		for (j = i; j <= n; ++j)
		{
			if (arr[j-1] % b == 0)
			{
				arr[j-1] /= b;
			}
		} 
	}

	return ret;
}

//see problem #3

bool is_prime(short n)
{
	short limit = (short) floor(sqrtf((float) n));
	short iter;
	for (iter = 2; iter <= limit; ++iter)
	{
		// if n divides iter completly, then it is not prime
		if (n % iter == 0)
			return false;
	}
	return true;
}

short _largest_pfaktor(short n, short start)
{
	if (is_prime(n)) return n;
	short iter;
	for (iter = start; iter < n; ++iter)
	{
		if (n % iter == 0 && is_prime(iter))
		{
			return _largest_pfaktor(n/iter, iter);
		}
	}

	return 0;
}

short largest_pfaktor(short n)
{
	return _largest_pfaktor(n, 2);
}
