#include "../include/parser.h"
#include "../include/libft.h"

int one_of(char c, char	*set)
{
	while (*set)
	{
		if(c == *set)
			return (1);
		set++;
	}
	return (0);
}

void	get_flags(char **s, format	*ptr)
{
	while (one_of(**s, "+-0 #"))
	{
		if (**s == ' ' && !ptr->space)
			ptr->space = TRUE;
		else if (**s == '-' && !ptr->minus)
			ptr->minus = TRUE;
		else if (**s == '+' && !ptr->plus)
			ptr->plus = TRUE;
		else if (**s == '0' && !ptr->zero)
			ptr->zero = TRUE;
		else if (**s == '#' && !ptr->hash)
			ptr->hash = TRUE;
		(*s)++;
	}
}

void	get_lenght(char **s, format	*ptr)
{
	size_t	num;

	num = 0;
	while (ft_isdigit(**s))
	{
		ptr->lenght_act = TRUE;
		if ((num * 10) + (**s - '0') <= 2147483647)
			num = (num * 10) + (**s - '0');
		(*s)++;
	}
	ptr->lenght = num ;
}
