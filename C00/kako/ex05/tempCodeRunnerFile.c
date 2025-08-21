void	ft_putcomma(void)
{
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < 10)
	{
		j = i;
		while (++j < 10)
		{
			k = j;
			while (++k < 10)
			{
				ft_putnums(i, j, k);
				if (i != 7 || j != 8 || k != 9)
				{
					ft_putcomma();
				}
			}
		}
	}
}

// int	main(void)
// {
// 	ft_print_comb();
// }
