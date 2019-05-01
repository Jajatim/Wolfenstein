# GENERIC
NAME = binaries$(SEP)prog$(EXT)
CC = gcc
CFLAGS = -Wall -Wextra

# INCLUDES
#INC = resources$(SEP)

# SOURCES
SRCDIR = src$(SEP)
SRC = main.c 

# OBJECTS
OBJDIR = src$(SEP)tmp$(SEP)
OBJ = $(SRC:.c=.o)

# OS DEPENDANT VARIABLES
# LINUX
ifeq ($(OS),Linux)
$(info Compiling for Linux.)
#EXT =
SEP = /
DEL = rm -f

# APPLE 
else ifeq ($(OS),Apple)
$(info Compiling for Apple.)
#EXT =
SEP = /
DEL = rm -f

# WINDOWS
else ifeq ($(OS),Windows_NT)
$(info Compiling for Windows.)
EXT = .exe
SEP = $(strip \)
#SEP = /
DEL = del /q

# OS NOT FOUND 
else
$(info No know OS found.)
err:
	exit
endif


# RULES
all: $(NAME)

$(NAME): $(OBJDIR)$(OBJ)
	$(CC) $(OBJDIR)$(OBJ) -o $(NAME)

$(OBJDIR)$(OBJ): $(SRCDIR)$(SRC)
	$(info Compiling $< into $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(DEL) $(OBJDIR)$(OBJ)

fclean: clean
	$(DEL) $(NAME)

re: fclean all


.PHONY: err, all, clean, fclean, re