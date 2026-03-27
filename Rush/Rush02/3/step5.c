#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 1024
#define MAX_DICT 100

typedef struct s_dict {
    int num;
    char *word;
} t_dict;

t_dict parse_line(char *line) {
    t_dict entry;
    char *colon_pos = strchr(line, ':');
    if (colon_pos) {
        *colon_pos = '\0';
        entry.num = atoi(line);
        while (*(colon_pos + 1) == ' ')
            colon_pos++;
        entry.word = strdup(colon_pos + 1);
    } else {
        entry.num = -1;
        entry.word = NULL;
    }
    return entry;
}

char *search_word(t_dict dict[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (dict[i].num == target)
            return dict[i].word;
    }
    return NULL;
}

void print_number_in_words(t_dict dict[], int size, int number) {
    if (number == 0) {
        printf("%s\n", search_word(dict, size, 0));
        return;
    }

    int thousands = number / 1000;
    int hundreds = (number / 100) % 10;
    int tens_units = number % 100;

    if (thousands > 0) {
        char *thousand_word = search_word(dict, size, thousands);
        if (!thousand_word) {
            printf("Error: cannot find %d in dictionary\n", thousands);
            return;
        }
        printf("%s thousand ", thousand_word);
    }

    if (hundreds > 0) {
        char *hundred_word = search_word(dict, size, hundreds);
        if (!hundred_word) {
            printf("Error: cannot find %d in dictionary\n", hundreds);
            return;
        }
        printf("%s hundred ", hundred_word);
    }

    if (tens_units > 0) {
        char *word = search_word(dict, size, tens_units);
        if (word) {
            printf("%s", word);
        } else {
            int tens = (tens_units / 10) * 10;
            int ones = tens_units % 10;
            char *tens_word = search_word(dict, size, tens);
            char *ones_word = search_word(dict, size, ones);
            if (!tens_word || (ones > 0 && !ones_word)) {
                printf("Error: cannot find %d in dictionary\n", tens_units);
                return;
            }
            printf("%s", tens_word);
            if (ones > 0)
                printf("-%s", ones_word);
        }
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    // 数字チェック
    for (int i = 0; argv[1][i]; i++) {
        if (!isdigit(argv[1][i])) {
            printf("Error: input must be a number\n");
            return 1;
        }
    }

    int fd;
    char buf[BUF_SIZE + 1];
    int size;
    char *file_content = NULL;
    int total_size = 0;

    fd = open("numbers.dict", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    while ((size = read(fd, buf, BUF_SIZE)) > 0) {
        buf[size] = '\0';
        file_content = realloc(file_content, total_size + size + 1);
        memcpy(file_content + total_size, buf, size + 1);
        total_size += size;
    }
    close(fd);

    // numbers.dictを辞書に変換
    t_dict dict[MAX_DICT];
    int dict_size = 0;
    int start = 0;
    for (int i = 0; i <= total_size; i++) {
        if (file_content[i] == '\n' || file_content[i] == '\0') {
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

    int number = atoi(argv[1]);
    print_number_in_words(dict, dict_size, number);

    free(file_content);
    return 0;
}
