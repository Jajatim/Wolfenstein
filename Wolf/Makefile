# GENERIC
NAME = binaries$(SEP)prog$(EXT)
CC = gcc
CFLAGS = -Wall -Wextra

# INCLUDES
#INC = resources$(SEP)

# SOURCES
SRCDIR =	$(wildcard src/*.c) \
			$(wildcard src/game/*.c) \
			$(wildcard src/menu/*.c)
#vpath=../src:../src/game
SRC = main.c test.c

# OBJECTS
#OBJDIR = src/tmp/
#OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))
OBJ = $(SRCDIR:.c=.o)


# OS DEPENDANT VARIABLES
# LINUX
ifeq ($(OS),Linux)
$(info Compiling for Linux.)
#EXT =
SEP = /
DEL = rm -f
FixPath = $1

# APPLE 
else ifeq ($(shell uname -s),Darwin)
$(info Compiling for Apple.)
#EXT =
SEP = /
DEL = rm -f
FixPath = $1
LIB = -F . -framework SDL2 -rpath .

# WINDOWS
else ifeq ($(OS),Windows_NT)
$(info Os : |$(OS)|, System : |$(shell uname -s)|. Compiling for Windows.)
EXT = .exe
SEP = $(strip \)
#SEP = /
DEL = del /q
FixPath = $(subst /,\,$1)

# OS NOT FOUND 
else
$(info Your OS |$(OS)| or your shell name |$(shell uname -s)| is not listed on this Makefile. Aborting.)
err:
	exit
endif



# RULES
all: $(NAME)

$(NAME): $(OBJ)
	$(info Compiling $@...)
	$(CC) $(call FixPath, $(OBJ)) -o $(call FixPath, $@) $(LIB)

%.o: %.c
#	$(info Compiling $< into $@)
	$(CC) $(CFLAGS) -c $(call FixPath, $<) -o $(call FixPath, $@)

clean:
	$(DEL) $(call FixPath, $(OBJ))

fclean: clean
	$(DEL) $(NAME)

re: fclean all


.PHONY: err, all, clean, fclean, re
