#include <stdio.h>
#include "include/ft_printf.h"


int main(void)
{
    int i = -42;
    int positive = 42;
    int zero = 0;
    unsigned int u = 42;
    unsigned int big = 4294967295u;
    char c = 'A';
    char *s = "Hello, World!";
    void *p = &i;

    // Basic conversions
    printf("=== BASIC ===\n");
	ft_printf("=== BASIC ===\n");
    printf("%d\n", i);
	ft_printf("%d\n", i);
    printf("%i\n", positive);
	ft_printf("%i\n", positive);
    printf("%u\n", u);
	ft_printf("%u\n", u);
    printf("%x\n", u);
	ft_printf("%x\n", u);
    printf("%X\n", u);
	ft_printf("%X\n", u);
    printf("%c\n", c);
	ft_printf("%c\n", c);
    printf("%s\n", s);
	ft_printf("%s\n", s);
    printf("%p\n", p);
	ft_printf("%p\n", p);
    printf("%%\n");
	ft_printf("%%\n");

    // Widths
    printf("\n=== WIDTHS ===\n");
	ft_printf("\n=== WIDTHS ===\n");
    printf("[%5d]\n", i);
	ft_printf("[%5d]\n", i);
    printf("[%10d]\n", positive);
	ft_printf("[%10d]\n", positive);
    printf("[%1d]\n", i);
	ft_printf("[%1d]\n", i);
    printf("[%20s]\n", s);
	ft_printf("[%20s]\n", s);
    printf("[%10c]\n", c);
	ft_printf("[%10c]\n", c);
    printf("[%10x]\n", u);
	ft_printf("[%10x]\n", u);

    // Flags
    printf("\n=== FLAGS ===\n");
	ft_printf("\n=== FLAGS ===\n");
    printf("[%+d]\n", positive);
	ft_printf("[%+d]\n", positive);
    printf("[%+d]\n", i);
	ft_printf("[%+d]\n", i);
    printf("[% d]\n", positive);
	ft_printf("[% d]\n", positive);
    printf("[% d]\n", i);
	ft_printf("[% d]\n", i);
    printf("[%-10d]\n", positive);
	ft_printf("[%-10d]\n", positive);
    printf("[%010d]\n", positive);
	ft_printf("[%010d]\n", positive);
    printf("[%#x]\n", u);
	ft_printf("[%#x]\n", u);
    printf("[%#X]\n", u);
	ft_printf("[%#X]\n", u);
    //printf("[%#o]\n", u);
	//ft_printf("[%#o]\n", u);

    // Precisions
    printf("\n=== PRECISIONS ===\n");
	ft_printf("\n=== PRECISIONS ===\n");
    printf("[%.0d]\n", zero);
	ft_printf("[%.0d]\n", zero);
    printf("[%.1d]\n", i);
	ft_printf("[%.1d]\n", i);
    printf("[%.5d]\n", positive);
	ft_printf("[%.5d]\n", positive);
    printf("[%.10d]\n", i);
	ft_printf("[%.10d]\n", i);
    printf("[%.5u]\n", u);
	ft_printf("[%.5u]\n", u);
    printf("[%.8x]\n", u);
	ft_printf("[%.8x]\n", u);
    printf("[%.5s]\n", s);
	ft_printf("[%.5s]\n", s);
    printf("[%.0s]\n", s);
	ft_printf("[%.0s]\n", s);

    // Width + precision
    printf("\n=== WIDTH + PRECISION ===\n");
	ft_printf("\n=== WIDTH + PRECISION ===\n");
    printf("[%10.5d]\n", positive);
	ft_printf("[%10.5d]\n", positive);
    printf("[%-10.5d]\n", positive);
	ft_printf("[%-10.5d]\n", positive);
    printf("[%010.5d]\n", positive);
	ft_printf("[%010.5d]\n", positive);
    printf("[%8.3x]\n", u);
	ft_printf("[%8.3x]\n", u);
    printf("[%10.5s]\n", s);
	ft_printf("[%10.5s]\n", s);
    printf("[%20.10s]\n", s);
	ft_printf("[%20.10s]\n", s);

    // Combined flags
    printf("\n=== COMBINED FLAGS ===\n");
	ft_printf("\n=== COMBINED FLAGS ===\n");
    printf("[%+010d]\n", positive);
	ft_printf("[%+010d]\n", positive);
    printf("[%+010d]\n", i);
	ft_printf("[%+010d]\n", i);
    printf("[% -010d]\n", i);
	ft_printf("[% -010d]\n", i);
    printf("[%#010x]\n", u);
	ft_printf("[%#010x]\n", u);
    printf("[%#10X]\n", u);
	ft_printf("[%#10X]\n", u);
    printf("[%-#10x]\n", u);
	ft_printf("[%-#10x]\n", u);

    // Zero and edge cases
    printf("\n=== EDGE CASES ===\n");
	ft_printf("\n=== EDGE CASES ===\n");
    printf("[%d]\n", zero);
	ft_printf("[%d]\n", zero);
    printf("[%.0d]\n", zero);
	ft_printf("[%.0d]\n", zero);
    printf("[%5.0d]\n", zero);
	ft_printf("[%5.0d]\n", zero);
    printf("[%+d]\n", zero);
	ft_printf("[%+d]\n", zero);
    printf("[%#x]\n", zero);
	ft_printf("[%#x]\n", zero);
    printf("[%#X]\n", zero);
	ft_printf("[%#X]\n", zero);
    //printf("[%#o]\n", zero);
	//ft_printf("[%#o]\n", zero);
    printf("[%u]\n", big);
	ft_printf("[%u]\n", big);
    printf("[%20p]\n", p);
	ft_printf("[%20p]\n", p);

    // Characters and strings
    printf("\n=== CHARACTERS AND STRINGS ===\n");
	ft_printf("\n=== CHARACTERS AND STRINGS ===\n");
    printf("[%5c]\n", c);
	ft_printf("[%5c]\n", c);
    printf("[%-5c]\n", c);
	ft_printf("[%-5c]\n", c);
    printf("[%5.3s]\n", s);
	ft_printf("[%5.3s]\n", s);
    printf("[%-15.5s]\n", s);
	ft_printf("[%-15.5s]\n", s);

    // Literal percent
    printf("\n=== PERCENT ===\n");
	ft_printf("\n=== PERCENT ===\n");
    printf("100%%\n");
	ft_printf("100%%\n");
    printf("[%5%]\n");
	ft_printf("[%5%]\n");
    printf("[%-5%]\n");
	ft_printf("[%-5%]\n");

    return 0;
}
