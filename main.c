
#include <stdio.h>
#include <limits.h>
#include "include/ft_printf.h"

int	main(void)
{
	////printf("\n========== BASIC TESTS ==========\n");
	////ft_printf("[%s]\n", "Hello");
	////printf("[%s]\n", "Hello");
	////ft_printf("[%s]\n", "");
	////printf("[%s]\n", "");
	////ft_printf("[%s]\n", "42");
	////printf("[%s]\n", "42");
	////ft_printf("[%s]\n", "Hello World");
	////printf("[%s]\n", "Hello World");

	////printf("\n========== WIDTH TESTS ==========\n");
	////ft_printf("[%10s]\n", "Hello");
	////printf("[%10s]\n", "Hello");
	////ft_printf("[%5s]\n", "Hello");
	////printf("[%5s]\n", "Hello");
	////ft_printf("[%3s]\n", "Hello");
	////printf("[%3s]\n", "Hello");
	////ft_printf("[%1s]\n", "Hello");
	////printf("[%1s]\n", "Hello");
	////ft_printf("[%0s]\n", "Hello");
	////printf("[%0s]\n", "Hello");
	////ft_printf("[%10s]\n", "");
	////printf("[%10s]\n", "");

	////printf("\n========== PRECISION TESTS ==========\n");
	////ft_printf("[%.0s]\n", "Hello");
	////printf("[%.0s]\n", "Hello");
	////ft_printf("[%.1s]\n", "Hello");
	////printf("[%.1s]\n", "Hello");
	////ft_printf("[%.2s]\n", "Hello");
	////printf("[%.2s]\n", "Hello");
	////ft_printf("[%.3s]\n", "Hello");
	////printf("[%.3s]\n", "Hello");
	////ft_printf("[%.5s]\n", "Hello");
	////printf("[%.5s]\n", "Hello");
	////ft_printf("[%.10s]\n", "Hello");
	////printf("[%.10s]\n", "Hello");
	////ft_printf("[%.20s]\n", "Hello");
	////printf("[%.20s]\n", "Hello");

	////printf("\n========== WIDTH + PRECISION ==========\n");
	////ft_printf("[%10.3s]\n", "Hello");
	////printf("[%10.3s]\n", "Hello");
	////ft_printf("[%10.0s]\n", "Hello");
	////printf("[%10.0s]\n", "Hello");
	////ft_printf("[%5.5s]\n", "Hello");
	////printf("[%5.5s]\n", "Hello");
	////ft_printf("[%3.5s]\n", "Hello");
	////printf("[%3.5s]\n", "Hello");
	////ft_printf("[%2.4s]\n", "Hello");
	////printf("[%2.4s]\n", "Hello");
	////ft_printf("[%1.1s]\n", "Hello");
	////printf("[%1.1s]\n", "Hello");
	////ft_printf("[%20.10s]\n", "Hello World");
	////printf("[%20.10s]\n", "Hello World");
	////ft_printf("[%5.2s]\n", "Hello");
	////printf("[%5.2s]\n", "Hello");

	////printf("\n========== FLAGS ==========\n");
	////ft_printf("[%-10s]\n", "Hello");
	////printf("[%-10s]\n", "Hello");
	////ft_printf("[%-5s]\n", "Hello");
	////printf("[%-5s]\n", "Hello");
	////ft_printf("[%+10s]\n", "Hello");
	////printf("[%+10s]\n", "Hello");
	////ft_printf("[% 10s]\n", "Hello");
	////printf("[% 10s]\n", "Hello");
	////ft_printf("[%#10s]\n", "Hello");
	////printf("[%#10s]\n", "Hello");
	////ft_printf("[%010s]\n", "Hello");
	////printf("[%010s]\n", "Hello");

	////printf("\n========== FLAGS + PRECISION ==========\n");
	////ft_printf("[%-10.3s]\n", "Hello");
	////printf("[%-10.3s]\n", "Hello");
	////ft_printf("[%-10.0s]\n", "Hello");
	////printf("[%-10.0s]\n", "Hello");
	////ft_printf("[%+10.3s]\n", "Hello");
	////printf("[%+10.3s]\n", "Hello");
	////ft_printf("[% 10.3s]\n", "Hello");
	////printf("[% 10.3s]\n", "Hello");
	////ft_printf("[%#10.3s]\n", "Hello");
	////printf("[%#10.3s]\n", "Hello");
	////ft_printf("[%010.3s]\n", "Hello");
	////printf("[%010.3s]\n", "Hello");
	////ft_printf("[%-5.2s]\n", "Hello");
	////printf("[%-5.2s]\n", "Hello");

	//printf("\n========== DYNAMIC WIDTH ==========\n");
	//ft_printf("[%*s]\n", 10, "Hello");
	//printf("[%*s]\n", 10, "Hello");
	//ft_printf("[%*s]\n", 3, "Hello");
	//printf("[%*s]\n", 3, "Hello");
	//ft_printf("[%*s]\n", -10, "Hello");
	//printf("[%*s]\n", -10, "Hello");

	//printf("\n========== DYNAMIC PRECISION ==========\n");
	//ft_printf("[%.*s]\n", 3, "Hello");
	//printf("[%.*s]\n", 3, "Hello");
	//ft_printf("[%.*s]\n", 0, "Hello");
	//printf("[%.*s]\n", 0, "Hello");
	//ft_printf("[%.*s]\n", -1, "Hello");
	//printf("[%.*s]\n", -1, "Hello");

	//printf("\n========== DYNAMIC WIDTH + PRECISION ==========\n");
	//ft_printf("[%*.*s]\n", 10, 3, "Hello");
	//printf("[%*.*s]\n", 10, 3, "Hello");
	//ft_printf("[%*.*s]\n", 5, 2, "Hello");
	//printf("[%*.*s]\n", 5, 2, "Hello");
	//ft_printf("[%*.*s]\n", -10, 3, "Hello");
	//printf("[%*.*s]\n", -10, 3, "Hello");
	//ft_printf("[%*.*s]\n", -5, -2, "Hello");
	//printf("[%*.*s]\n", -5, -2, "Hello");

	//printf("\n========== EDGE CASES ==========\n");
	//ft_printf("[%100s]\n", "Hello");
	//printf("[%100s]\n", "Hello");
	//ft_printf("[%.100s]\n", "Hello");
	//printf("[%.100s]\n", "Hello");
	//ft_printf("[%100.100s]\n", "Hello");
	//printf("[%100.100s]\n", "Hello");
	//ft_printf("[%100.0s]\n", "Hello");
	//printf("[%100.0s]\n", "Hello");
	//ft_printf("[%1.100s]\n", "Hello");
	//printf("[%1.100s]\n", "Hello");
	//ft_printf("[%100.1s]\n", "Hello");
	//printf("[%100.1s]\n", "Hello");
	//ft_printf("[%.s]\n", "Hello");
	//printf("[%.s]\n", "Hello");

	//printf("\n========== RETURN VALUES ==========\n");
	printf("ft_printf return: %d\n", ft_printf(" %-9p %-10p ", LONG_MIN, LONG_MAX));
	printf("printf return:    %d\n", printf(" %-9p %-10p ", LONG_MIN, LONG_MAX));
	//printf("num : %d\n", ft_printf("%d\n", -1));

	return (0);
}
