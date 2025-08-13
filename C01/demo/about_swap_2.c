#include <unistd.h>

// 値を表示する関数
void	ft_putnbr(int n)
{
	char c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

// 値を入れ替える（アドレス渡しバージョン）
void	ft_swap_pointer(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// 値を入れ替える（値渡しバージョン）
// これだと元の変数は変わらない
void	ft_swap_value(int a, int b)
{
	int	temp;

	temp = a;
	a = b;
	b = temp;
}

int	main(void)
{
	int x = 42;
	int y = 99;

	// 値渡し（&なし）
	write(1, "Before value swap: x=", 22);
	ft_putnbr(x);
	write(1, ", y=", 4);
	ft_putnbr(y);
	write(1, "\n", 1);

	ft_swap_value(x, y);

	write(1, "After value swap:  x=", 22);
	ft_putnbr(x);
	write(1, ", y=", 4);
	ft_putnbr(y);
	write(1, "\n\n", 2);

	// アドレス渡し（&あり）
	write(1, "Before pointer swap: x=", 24);
	ft_putnbr(x);
	write(1, ", y=", 4);
	ft_putnbr(y);
	write(1, "\n", 1);

	ft_swap_pointer(&x, &y);

	write(1, "After pointer swap:  x=", 24);
	ft_putnbr(x);
	write(1, ", y=", 4);
	ft_putnbr(y);
	write(1, "\n", 1);

	return 0;
}
