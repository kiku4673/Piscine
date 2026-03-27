#include <stdio.h>
#include <stdlib.h>

#define N 4

int grid[N][N];
int clues[4][N]; // 上, 下, 左, 右のヒント

// 同じ行や列に同じ数字がないか確認
int ok(int row, int col, int val) {
    for(int i=0; i<N; i++) {
        if(grid[row][i] == val || grid[i][col] == val) return 0;
    }
    return 1;
}

// 入力文字列からヒントを読み込む
int parse_input(char *s) {
    int i=0, j=0;
    while(s[i] != '\0' && j<16) {
        if(s[i] >= '1' && s[i] <= '4') {
            clues[j/4][j%4] = s[i] - '0';
            j++;
        }
        i++;
    }
    return (j == 16);
}

// バックトラックで盤面を完成させる
int solve(int row, int col) {
    if(row == N) return 1; // 最後まで埋まったら完成

    int next_row = (col == N-1) ? row+1 : row;
    int next_col = (col == N-1) ? 0 : col;

    for(int val=1; val<=N; val++) {
        if(ok(row, col, val)) {
            grid[row][col] = val;              // 候補を置く
            if(solve(next_row, next_col)) return 1; // 成功したら終了
            grid[row][col] = 0;                // 失敗したら戻す
        }
    }
    return 0; // どの数字も置けなければ失敗
}

// 盤面を表示
void print_grid() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) printf("%d ", grid[i][j]);
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if(argc != 2) {
        printf("Error\n");
        return 1;
    }

    if(!parse_input(argv[1])) {
        printf("Error\n");
        return 1;
    }

    // gridを初期化
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            grid[i][j] = 0;

    if(solve(0,0)) {
        print_grid();
    } else {
        printf("Error\n");
    }

    return 0;
}


// #include <stdio.h>

// #define N 4

// int grid[N][N]; // ビルの高さを置く場所

// // 同じ行や列に同じ数字がないかチェック
// int ok(int row, int col, int val){
//     for(int i=0;i<N;i++){
//         if(grid[row][i]==val || grid[i][col]==val) return 0;
//     }
//     return 1;
// }

// // 1マスずつ数字を置いて完成させる
// int solve(int row, int col){
//     if(row==N) return 1; // すべて置けたら完成
//     int next_row = (col==N-1)? row+1: row;
//     int next_col = (col==N-1)? 0: col;

//     for(int val=1; val<=N; val++){
//         if(ok(row,col,val)){
//             grid[row][col]=val;          // 候補を置く
//             if(solve(next_row,next_col)) return 1; // 完成できたら終了
//             grid[row][col]=0;            // 違ったら戻す
//         }
//     }
//     return 0;
// }

// int main(){
//     if(solve(0,0)){
//         for(int i=0;i<N;i++){
//             for(int j=0;j<N;j++) printf("%d ",grid[i][j]);
//             printf("\n");
//         }
//     } else {
//         printf("Error\n");
//     }
// }
