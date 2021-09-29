NAME = get_next_line

CC = CLANG

CFLAGS = -Wall -Wextra -Werror

$(NAME):
	$(CC) $(CFLAGS) *.c *.h 

CLEAN:
	rm -rf *.h.gch