int	calc_num_base(int base, long num)
{
	int s;

	s = 0;
	if (!num)
		return (0);
	if (base == 10 && num < 0)
	{
		s = 1;
		num =  -num;
	}
	if (base == 16 && num < 0)
		return (calc_num_base(base, ((unsigned int) num) / base) + 1);
	else
		return (calc_num_base(base, num / base) + 1 + s);
}
