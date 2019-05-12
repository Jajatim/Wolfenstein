# GENERIC
NAME = prog
CC = gcc
CFLAGS = -Wall -Wextra

# INCLUDES
#INC = 

# SOURCES
SRCDIR =	$(wildcard src/*.c) \
			$(wildcard src/play/*.c) \
			$(wildcard src/menu/*.c) \
			$(wildcard src/utils/*.c)
#vpath=../src:../src/game
#SRC = main.c test.c

# OBJECTS
#OBJDIR = src/tmp/
#OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))
OBJ = $(SRCDIR:.c=.o)


# OS DEPENDANT VARIABLES
# LINUX
ifeq ($(shell uname -s),Linux)
$(info Compiling for Linux.)
DEL = rm -f
FixPath = $1
LIB = `sdl2-config --cflags --static-libs`

# APPLE 
else ifeq ($(shell uname -s),Darwin)
$(info Compiling for Apple.)
DEL = rm -f
FixPath = $1
LIB = -framework SDL2

# WINDOWS
else ifeq ($(OS),Windows_NT)
$(info Compiling for Windows.)
EXT = .exe
DEL = del /q
FixPath = $(subst /,\,$1)
SDLPATH = -Iresources/lib
LIB = -Lresources/lib -lmingw32 -lSDL2main -lSDL2

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
	$(CC) $(call FixPath, $(OBJ)) -o $(call FixPath, $@) $(call FixPath, $(LIB))

%.o: %.c
#	$(info Compiling $< into $@)
	$(CC) $(CFLAGS) -c $(call FixPath, $<) -o $(call FixPath, $@) $(call FixPath, $(SDLPATH))

clean:
	$(DEL) $(call FixPath, $(OBJ))

fclean: clean
	$(DEL) $(call FixPath, $(NAME)$(EXT))

re: fclean all


.PHONY: err, all, clean, fclean, re
