/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <kyamanak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:45:14 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/08 10:21:07 by kyamanak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <unistd.h>

void ft_print_alphabet_desc(void)
{
    char alphabet;
    alphabet = 'z';
    while (alphabet >= 'a')
    {
        // write関数を使用して現在の文字を標準出力に出力する
        // 第1引数: ファイルディスクリプタ (1は標準出力を意味する)
        // 第2引数: 出力するデータのポインタ
        // 第3引数: 出力するデータのバイト数
        write(1, &alphabet, 1);

        // 前の文字に進む
        alphabet--;
    }
}

int main(void)
{
}