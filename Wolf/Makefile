
NAME = prog$(EXT)
CC = gcc
CFLAGS = -Wall -Wextra

#INC = resources$(SEP)

SRCDIR = src$(SEP)
SRC = main.c

OBJDIR = src$(SEP)tmp$(SEP)
OBJ = $(SRC:.c=.o)


ifeq ($(OS),Linux)
$(info Compiling for Linux.)
#EXT =
SEP = /
DEL = rm -f


else ifeq ($(OS),Apple)
$(info Compiling for Apple.)
#EXT =
SEP = /
DEL = rm -f


else ifeq ($(OS),Windows_NT)
$(info Compiling for Windows.)
EXT = .exe
SEP = $(strip \)
DEL = del /q


else
$(info No know OS found.)
err:
	exit
endif

all: $(NAME)

$(NAME): $(OBJDIR)$(OBJ)
	$(CC) $(OBJDIR)$(OBJ) -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(info Compiling $< into $@)
	$(CC) $(FLAGS) -c $< -o $(OBJDIR)$@

clean:
	$(DEL) $(OBJDIR)$(OBJ)

fclean: clean
	$(DEL) $(NAME)

re: fclean all


.PHONY: err, all, clean, fclean, re