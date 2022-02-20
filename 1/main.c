#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>


float f(float y, int n, float x)
{
	float z = 1;
	for (int i = 0; i < n; i++) z *= y;
	return z - x;
}

float radical(float s, float d, int n, float x)
{
	if (d - s <= 0.000001) return s;
	else
	{
		float m = (s + d)/2;
		if (f(m, n, x) == 0) return m;
		else if (f(m, n, x) < 0) return radical(m, d, n, x);
		else return radical(s, m, n, x);
	}
}

// n = ordinul radicalului 

int main()
{
	float x;
	int n=2;
	printf("Cititi x: ");
	if (!scanf("%f", &x)) exit(1);
	if(x>=1)
	printf("%f\n",radical(0, x, n, x));
	else printf("%f\n", radical(0, 1, n, x));
	return 0;
}