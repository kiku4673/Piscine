#include <stdio.h>
#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);

void test_case(char *str, char *base, int expected, char *description)
{
    int result = ft_atoi_base(str, base);
    printf("Test: %s\n", description);
    printf("Input: str=\"%s\", base=\"%s\"\n", 
           str ? str : "NULL", base ? base : "NULL");
    printf("Expected: %d, Got: %d", expected, result);
    if (result == expected)
        printf(" ✅ PASS\n");
    else
        printf(" ❌ FAIL\n");
    printf("---\n");
}

int main(void)
{
    printf("=== ft_atoi_base テスト ===\n\n");

    // 基本的な2進数テスト
    test_case("1010", "01", 10, "2進数: 1010 → 10");
    test_case("1111", "01", 15, "2進数: 1111 → 15");
    test_case("0", "01", 0, "2進数: 0 → 0");

    // 16進数テスト
    test_case("FF", "0123456789ABCDEF", 255, "16進数: FF → 255");
    test_case("A0", "0123456789ABCDEF", 160, "16進数: A0 → 160");
    test_case("10", "0123456789ABCDEF", 16, "16進数: 10 → 16");

    // 10進数テスト
    test_case("123", "0123456789", 123, "10進数: 123 → 123");
    test_case("42", "0123456789", 42, "10進数: 42 → 42");

    // 8進数テスト
    test_case("17", "01234567", 15, "8進数: 17 → 15");
    test_case("77", "01234567", 63, "8進数: 77 → 63");

    // 符号テスト
    test_case("-1010", "01", -10, "負の2進数: -1010 → -10");
    test_case("+123", "0123456789", 123, "正の10進数: +123 → 123");
    test_case("--42", "0123456789", 42, "二重マイナス: --42 → 42");
    test_case("---42", "0123456789", -42, "三重マイナス: ---42 → -42");
    test_case("+-42", "0123456789", -42, "プラスマイナス: +-42 → -42");

    // 空白テスト
    test_case("   123", "0123456789", 123, "先頭空白: '   123' → 123");
    test_case("\t\n 42", "0123456789", 42, "タブ改行空白: '\\t\\n 42' → 42");

    // 無効なベーステスト
    test_case("123", "", 0, "空のベース → 0");
    test_case("123", "1", 0, "1文字ベース → 0");
    test_case("123", "01+", 0, "プラス含むベース → 0");
    test_case("123", "01-", 0, "マイナス含むベース → 0");
    test_case("123", "01 ", 0, "空白含むベース → 0");
    test_case("123", "011", 0, "重複文字ベース → 0");

    // NULLポインタテスト
    test_case(NULL, "01", 0, "NULL文字列 → 0");
    test_case("123", NULL, 0, "NULLベース → 0");

    // エッジケーステスト
    test_case("", "01", 0, "空文字列 → 0");
    test_case("abc123", "0123456789", 0, "無効文字で開始 → 0");
    test_case("123abc", "0123456789", 123, "途中で無効文字 → 123");
    
    // カスタムベーステスト
    test_case("poney", "poney", 194, "ベース 'poney': poney → 194");
    test_case("01", "poney", 0, "ベース 'poney': 01 → 0 (無効文字)");
    test_case("ey", "poney", 19, "ベース 'poney': ey → 19 (3*5+4)");

    printf("\n=== テスト完了 ===\n");
    return (0);
}