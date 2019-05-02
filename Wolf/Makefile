# GENERIC
NAME = binaries$(SEP)prog$(EXT)
CC = gcc
CFLAGS = -Wall -Wextra

# INCLUDES
#INC = resources$(SEP)

# SOURCES
SRCDIR =	$(wildcard src/*.c) \
			$(wildcard src/game/*.c)
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
else ifeq ($(OS),Apple)
$(info Compiling for Apple.)
#EXT =
SEP = /
DEL = rm -f
FixPath = $1

# WINDOWS
else ifeq ($(OS),Windows_NT)
$(info Compiling for Windows.)
EXT = .exe
SEP = $(strip \)
#SEP = /
DEL = del /q
FixPath = $(subst /,\,$1)

# OS NOT FOUND 
else
$(info No know OS found.)
err:
	exit
endif



# RULES
all: $(NAME)

$(NAME): $(OBJ)
	$(info Compiling $@...)
	$(CC) $(call FixPath, $(OBJ)) -o $(call FixPath, $@)

%.o: %.c
#	$(info Compiling $< into $@)
	$(CC) $(CFLAGS) -c $(call FixPath, $<) -o $(call FixPath, $@)

clean:
	$(DEL) $(call FixPath, $(OBJ))

fclean: clean
	$(DEL) $(NAME)

re: fclean all


.PHONY: err, all, clean, fclean, re