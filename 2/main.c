#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

float f(float x, int a, float n)
{
	return pow(a, x)-n;
}

float logaritm(float s, float d, int a, float n)
{
	if (d - s <= 0.001) return s;
	else
	{
		float m = (d + s) / 2;
		if (f(m, a, n) == 0) return m;
		else if (f(m, a, n) < 0) return logaritm(m, d, a, n);
				else return logaritm(s, m, a, n);
	}
}


int main()
{
	float n;
	// a = baza
	int a=10;
	printf("Cititi n: ");
	if (!scanf("%f", &n)) exit(1);

	if (n >= 1)
		printf("%f\n", logaritm(0, n, a, n));
	else printf("%f\n", logaritm(INT_MIN, 0, a, n));

	return 0;
}