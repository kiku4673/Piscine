#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);

int	main(void)
{
	ft_putnbr_base(42, "01");
	write(1, "\n", 1);
	ft_putnbr_base(-42, "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base(255, "0123456789ABCDEF");
	write(1, "\n", 1);
	ft_putnbr_base(123, "poneyvif");
	write(1, "\n", 1);
	ft_putnbr_base(123, "");             // 無効 → 出力なし
	write(1, "\n", 1);
	ft_putnbr_base(123, "1123456789");   // 無効 → 出力なし
	write(1, "\n", 1);
}
