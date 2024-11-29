#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int deneme(int b, ...)
{
	va_list a;
	int toplam;

	toplam = 0;
	va_start(a, b);
	for(int i = 0; i < b; i++)
	{
		toplam += va_arg(a, int);
	}
	va_end(a);
	return (toplam);
}
int main()
{
	int result = deneme(2, 32, 7,5);
	ft_printf("%d", result);
}