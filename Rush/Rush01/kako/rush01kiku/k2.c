/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:42:26 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/16 15:30:44 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define N 4

// 左から見えるビルの数を再帰で数える
int	count_visible_rec(int row[N], int idx, int max, int count)
{
	if (idx == N)
	{
		return (count);
	}
    if (row[idx] > max)
	{
		return (count_visible_rec(row, idx + 1, row[idx], count + 1));
	}
    return count_visible_rec(row, idx+1, max, count);
}

// 行または列のチェック（左右・上下）を再帰で
int check_row_rec(int grid[N][N], int clues[4][N], int row, int col) {
    if(col == N) return 1;
    int left_row[N], right_row[N], up_col[N], down_col[N];

    // 左右
    int fill_lr(int c) {
        if(c == N) return 1;
        left_row[c] = grid[row][c];
        right_row[c] = grid[row][N-1-c];
        return fill_lr(c+1);
    }

    fill_lr(0);

    if(count_visible_rec(left_row,0,0,0) != clues[2][row]) return 0; // 左
    if(count_visible_rec(right_row,0,0,0) != clues[3][row]) return 0; // 右

    // 上下
    int fill_ud(int r) {
        if(r == N) return 1;
        up_col[r] = grid[r][col];
        down_col[r] = grid[N-1-r][col];
        return fill_ud(r+1);
    }

    fill_ud(0);

    if(count_visible_rec(up_col,0,0,0) != clues[0][col]) return 0;    // 上
    if(count_visible_rec(down_col,0,0,0) != clues[1][col]) return 0;  // 下

    return check_row_rec(grid, clues, row+1, col); // 次の行
}

// 同じ行や列に同じ数字がないか確認
int ok(int grid[N][N], int row, int col, int val, int i) {
    if(i == N) return 1;
    if(grid[row][i] == val || grid[i][col] == val) return 0;
    return ok(grid, row, col, val, i+1);
}

// 候補の数字を順番に試す（再帰）
int try_val(int grid[N][N], int clues[4][N], int row, int col, int val) {
    if(val > N) return 0;
    if(ok(grid,row,col,val,0)) {
        grid[row][col] = val;
        int next_row = (col == N-1) ? row+1 : row;
        int next_col = (col == N-1) ? 0 : col+1;

        if(next_row == N) {
            // 最後のマスまで置いたらヒントチェック
            int final_check(int r) { 
                if(r == N) return 1;
                int c = 0;
                int row_ok = (count_visible_rec(grid[r],0,0,0) == clues[2][r]); // 左
                int rev_row_ok = (count_visible_rec(grid[r],0,0,0) == clues[3][r]); // 右
                return row_ok && rev_row_ok && final_check(r+1);
            }
            if(final_check(0)) return 1;
        } else if(try_val(grid, clues, next_row, next_col, 1)) {
            return 1;
        }
        grid[row][col] = 0;
    }
    return try_val(grid, clues, row, col, val+1);
}

// バックトラック本体
int solve(int grid[N][N], int clues[4][N], int row, int col) {
    if(row == N) return 1;
    return try_val(grid, clues, row, col, 1);
}

// 入力を読み込む
int parse_input(char *s, int clues[4][N]) {
    int i=0, j=0;
    if(*s == '\0') return 0;
    int parse_rec(char *str, int j) {
        if(str[0] == '\0') return (j == 16);
        if(str[0] >= '1' && str[0] <= '4') {
            clues[j/4][j%4] = str[0]-'0';
            return parse_rec(str+1, j+1);
        } else {
            return parse_rec(str+1, j);
        }
    }
    return parse_rec(s, 0);
}

// 盤面表示
void print_grid(int grid[N][N], int r, int c) {
    if(r == N) return;
    if(c == N) {
        printf("\n");
        print_grid(grid,r+1,0);
        return;
    }
    printf("%d ", grid[r][c]);
    print_grid(grid,r,c+1);
}

int main(int argc, char **argv) {
    if(argc != 2){
        printf("Error\n");
        return 1;
    }

    int clues[4][N];
    int grid[N][N] = {0};

    if(!parse_input(argv[1], clues)){
        printf("Error\n");
        return 1;
    }

    if(solve(grid, clues, 0, 0))
        print_grid(grid,0,0);
    else
        printf("Error\n");

    return 0;
}
