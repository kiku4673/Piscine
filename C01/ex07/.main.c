#include <stdio.h>

// プロトタイプ宣言（実装ファイルに定義されていると仮定）
void ft_rev_int_tab(int *tab, int size);

int main(void)
{
    int arr[] = { 10, 20, 30, 40, 50 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before reversing:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    ft_rev_int_tab(arr, n);

    printf("After reversing:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
