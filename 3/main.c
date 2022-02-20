#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int fib(int n)
{
	if ((n == 0) || (n==1)) return n;
	if (n > 0) return fib(n - 1) + fib(n - 2);
	else return fib(n + 2) - fib(n + 1);
}

int fib2(int n, int memo[])
{
	if ((n == 0) || (n == 1)) return n;
	int m = abs(n);
	if (memo[m] == 0)
	{
		if (n > 0) memo[m] = fib2(n - 1, memo) + fib2(n - 2, memo);
		else memo[m] = fib2(n + 2, memo) - fib2(n + 1, memo);
	}
	return memo[m];
}

int main()
{
	int n,m,p;

	printf("Cititi n: ");
	if (!scanf("%d", &n)) exit(1);

	int* v = (int*)calloc(abs(n) + 1, sizeof(int));

	clock_t begin = clock();
	
	m=fib(n);

	clock_t end = clock();
	double t1 = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Fibonacci fara memoizare:%d %16.15lf\n", m, t1);

	begin = clock();

	p = fib2(n,v);

	end = clock();
	double t2 = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("Fibonacci cu memoizare:%d %16.15lf\n", p, t2);

	
	free(v);
	return 0;
}