#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	test1[10] = "abcdef";
	char	test2[20] = "あいうえお";

	int	len1, len2;

	//test1の文字列の長さを取得
	len1 = strlen(test1);

	//test2の文字列の長さを取得
	len2 = strlen(test2);

	//表示
	printf("test1の文字列の長さは→%d\n",len1);
	printf("test2の文字列の長さは→%d\n",len2);

	return 0;
}