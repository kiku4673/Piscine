#include <stdio.h>
#include <string.h>
#include <unistd.h>

// あなたの実装
char	*ft_strncpy(char *dest, char *src, unsigned int n);
// {
// 	unsigned int	i;

// 	i = 0;
// 	while (src[i] != '\0' && i < n)
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	while (i < n)
// 	{
// 		dest[i] = '\0';
// 		i++;
// 	}
// 	return (dest);
// }

// テスト用のヘルパー関数
void print_buffer(char *buf, int size, const char *label)
{
	printf("%s: \"", label);
	for (int i = 0; i < size; i++)
	{
		if (buf[i] == '\0')
			printf("\\0");
		else if (buf[i] >= 32 && buf[i] <= 126)
			printf("%c", buf[i]);
		else
			printf("\\x%02x", (unsigned char)buf[i]);
	}
	printf("\"\n");
}

int compare_buffers(char *buf1, char *buf2, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (buf1[i] != buf2[i])
			return 0;
	}
	return 1;
}

void test_case(char *src, int n, const char *description)
{
	char ft_dest[20];
	char std_dest[20];
	
	// バッファを初期化（テスト用に0xAAで埋める）
	memset(ft_dest, 0xAA, sizeof(ft_dest));
	memset(std_dest, 0xAA, sizeof(std_dest));
	
	// 両方の関数を実行
	ft_strncpy(ft_dest, src, n);
	strncpy(std_dest, src, n);
	
	printf("\n=== %s ===\n", description);
	printf("Source: \"%s\"\n", src);
	printf("n: %d\n", n);
	print_buffer(ft_dest, n > 15 ? 15 : n, "ft_strncpy ");
	print_buffer(std_dest, n > 15 ? 15 : n, "strncpy    ");
	
	if (compare_buffers(ft_dest, std_dest, n))
		printf("✅ PASS\n");
	else
		printf("❌ FAIL\n");
}

int main(void)
{
	printf("=== strncpy テストプログラム ===\n");
	
	// テストケース1: 通常のコピー（ソースがnより短い）
	test_case("hello", 10, "ソースがnより短い場合");
	
	// テストケース2: ソースがnと同じ長さ
	test_case("hello", 5, "ソースがnと同じ長さ");
	
	// テストケース3: ソースがnより長い
	test_case("hello world", 5, "ソースがnより長い場合");
	
	// テストケース4: 空文字列
	test_case("", 5, "空文字列");
	
	// テストケース5: n = 0
	test_case("hello", 0, "n = 0の場合");
	
	// テストケース6: n = 1
	test_case("hello", 1, "n = 1の場合");
	
	// テストケース7: 長い文字列の一部をコピー
	test_case("This is a very long string", 8, "長い文字列の一部");
	
	return 0;
}