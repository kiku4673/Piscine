#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1024

// 辞書データを保存する構造体
typedef struct s_dict
{
    int num;       // 数字
    char *word;    // 英単語
} t_dict;

// 1行のデータを構造体に変換する関数
t_dict parse_line(char *line)
{
    t_dict entry;
    char *colon_pos = strchr(line, ':');  // ":" の位置を探す

    if (colon_pos)
    {
        *colon_pos = '\0';                // ":"を区切り文字として終端
        entry.num = atoi(line);           // 左側を数字に変換
        entry.word = strdup(colon_pos + 1); // 右側の単語をコピー
    }
    else
    {
        entry.num = -1;
        entry.word = NULL;
    }
    return entry;
}

int main(void)
{
    int fd;
    char buf[BUF_SIZE + 1];
    int size;
    char *file_content = NULL;
    int total_size = 0;

    // ファイルを開く
    fd = open("numbers.dict", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    // ファイルを全部読み込む
    while ((size = read(fd, buf, BUF_SIZE)) > 0)
    {
        buf[size] = '\0';
        // メモリを再確保して読み込んだデータをつなげる
        file_content = realloc(file_content, total_size + size + 1);
        memcpy(file_content + total_size, buf, size + 1);
        total_size += size;
    }
    close(fd);

    // ファイルの中身を1行ずつ分割
    char *line = strtok(file_content, "\n");
    while (line != NULL)
    {
        t_dict entry = parse_line(line);
        if (entry.word)
            printf("%d -> %s\n", entry.num, entry.word);
        line = strtok(NULL, "\n");
    }

    free(file_content);
    return 0;
}
