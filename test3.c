
#include "include/ft_printf.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <limits.h>

int ft_printf(const char *format, ...);

#define TEST(fmt, ...) do { \
    printf("\n========================================\n"); \
    printf("FORMAT: %s\n", fmt); \
    printf("----------------------------------------\n"); \
    printf("ORIGINAL : "); \
    fflush(stdout); \
    printf(fmt, ##__VA_ARGS__); \
    printf("\n"); \
    fflush(stdout); \
    printf("FT_PRINTF: "); \
    fflush(stdout); \
    ft_printf(fmt, ##__VA_ARGS__); \
    printf("\n"); \
    fflush(stdout); \
} while (0)
int main(void)
{
    /* d and i */
    TEST("|%d|", 0);
    TEST("|%.0d|", 0);
    TEST("|%10.0d|", 0);
    TEST("|%-10.0d|", 0);
    TEST("|%+10.0d|", 0);
    TEST("|% 10.0d|", 0);
    TEST("|%010d|", 42);
    TEST("|%-010d|", 42);
    TEST("|%+010d|", 42);
    TEST("|%-+10d|", 42);
    TEST("|% 10d|", 42);
    TEST("|%+ 10d|", 42);
    TEST("|%d|", INT_MIN);
    TEST("|%d|", INT_MAX);

    /* u */
    TEST("|%u|", 0);
    TEST("|%u|", UINT_MAX);
    TEST("|%010u|", 42);
    TEST("|%-10u|", 42);
    TEST("|%10.5u|", 42);
    TEST("|%010.5u|", 42);

    /* x and X */
    TEST("|%x|", 0);
    TEST("|%#x|", 0);
    TEST("|%#X|", 0);
    TEST("|%#x|", 42);
    TEST("|%#X|", 42);
    TEST("|%010x|", 42);
    TEST("|%-10x|", 42);
    TEST("|%#10x|", 42);
    TEST("|%#010x|", 42);
    TEST("|%-#10x|", 42);
    TEST("|%#.0x|", 0);
    TEST("|%#10.5x|", 42);

    /* c */
    TEST("|%c|", 'A');
    TEST("|%5c|", 'A');
    TEST("|%-5c|", 'A');
    TEST("|%05c|", 'A');

    /* s */
    TEST("|%s|", "Hello");
    TEST("|%10s|", "Hello");
    TEST("|%-10s|", "Hello");
    TEST("|%.3s|", "Hello");
    TEST("|%10.3s|", "Hello");
    TEST("|%-10.3s|", "Hello");

    /* p */
    TEST("|%p|", (void *)0);
    TEST("|%p|", (void *)42);
    TEST("|%20p|", (void *)42);
    TEST("|%-20p|", (void *)42);

    /* % */
    TEST("|%%|");
    TEST("|%5%|");
    TEST("|%-5%|");
    TEST("|%05%|");

    return 0;
}
