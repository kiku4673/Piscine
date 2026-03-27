# 実行ファイル名
NAME = rush-02

# ソースコード一覧

SRCS = main.c io_utils.c str_utils.c file_utils.c


# オブジェクトファイル一覧（.cを.oに置き換え）
OBJS = $(SRCS:.c=.o)

# コンパイラ
CC = cc
CFLAGS = -Wall -Wextra -Werror

# make と打ったときに実行されるルール
all: $(NAME)

# 実行ファイルを作る手順
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# 掃除コマンド（.oファイル削除）
clean:
	rm -f $(OBJS)

# 実行ファイルも消す
fclean: clean
	rm -f $(NAME)

# きれいに作り直す
re: fclean all
