#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>

int cate_tipuri_monede = 4;

int da_rest(int rest, int* monede, int tip_moneda)
{
	if (tip_moneda >= cate_tipuri_monede - 1) return 1;

	int cate_moduri = 0;
	int val = monede[tip_moneda];
	int i, ce_ramane;
	for (i = 0; i * val <= rest; i++)
	{
		ce_ramane = rest - i * val;
		cate_moduri += da_rest(ce_ramane, monede, tip_moneda + 1);
	}

	return cate_moduri;
}


int da_rest2(int rest, int* monede, int tip_moneda, int aux[100][4])
{
	if (aux[rest][tip_moneda] > 0) return aux[rest][tip_moneda];

	if (tip_moneda >= cate_tipuri_monede - 1) return 1;

	int cate_moduri = 0;
	int val = monede[tip_moneda];
	int i, ce_ramane;
	for (i = 0; i * val <= rest; i++)
	{
		ce_ramane = rest - i * val;
		cate_moduri += da_rest2(ce_ramane, monede, tip_moneda + 1,aux);
	}
	aux[rest][tip_moneda] = cate_moduri;
	return cate_moduri;
}

int main()
{	
	int n=99;
	int monede[4] = { 25,10,5,1 };
	printf("%d\n", da_rest(n, monede, 0));
	int aux[100][4] = { 0 };
	printf("%d\n", da_rest2(n, monede, 0,aux));

	return 0; 
}