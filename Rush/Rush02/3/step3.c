#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1024
#define MAX_DICT 100

typedef struct s_dict
{
    int num;
    char *word;
} t_dict;

// 1行を解析して t_dict に変換
t_dict parse_line(char *line)
{
    t_dict entry;
    char *colon_pos = strchr(line, ':');
    if (colon_pos)
    {
        *colon_pos = '\0';
        entry.num = atoi(line);
        while (*(colon_pos + 1) == ' ')
            colon_pos++;
        entry.word = strdup(colon_pos + 1);
    }
    else
    {
        entry.num = -1;
        entry.word = NULL;
    }
    return entry;
}

// 数字を検索
char *search_word(t_dict dict[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (dict[i].num == target)
            return dict[i].word;
    }
    return NULL;
}

int main(void)
{
    int fd;
    char buf[BUF_SIZE + 1];
    int size;
    char *file_content = NULL;
    int total_size = 0;

    fd = open("numbers.dict", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    // ファイル全体を読み込む
    while ((size = read(fd, buf, BUF_SIZE)) > 0)
    {
        buf[size] = '\0';
        file_content = realloc(file_content, total_size + size + 1);
        memcpy(file_content + total_size, buf, size + 1);
        total_size += size;
    }
    close(fd);

    // numbers.dict の内容を1行ずつ解析
    t_dict dict[MAX_DICT];
    int dict_size = 0;
    int start = 0;
    for (int i = 0; i <= total_size; i++)
    {
        if (file_content[i] == '\n' || file_content[i] == '\0')
        {
            int line_len = i - start;
            if (file_content[i] == '\0') line_len++;

            char *line = malloc(line_len + 1);
            strncpy(line, file_content + start, line_len);
            line[line_len] = '\0';

            dict[dict_size] = parse_line(line);
            dict_size++;

            free(line);
            start = i + 1;
        }
    }

    // ユーザーに数字を入力させる
    int target;
    printf("数字を入力してください: ");
    scanf("%d", &target);

    char *result = search_word(dict, dict_size, target);
    if (result)
        printf("%d は \"%s\" です。\n", target, result);
    else
        printf("%d は辞書にありません。\n", target);

    free(file_content);
    return 0;
}
