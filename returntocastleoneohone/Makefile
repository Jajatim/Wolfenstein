# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: sifouche <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/12/07 15:32:55 by sifouche     #+#   ##    ##    #+#        #
#    Updated: 2019/04/18 19:29:34 by sifouche    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = RTCOOO

FLAGS = -Wall -Wextra

INCDIR = ./inc/
SRCDIR = ./src/

SDL = -F . -framework SDL2 -rpath .
SDLDIR = ./SDL2.framework/Headers/

OBJ = $(SRC:.c=.o)

INC =	$(INCDIR)wolf.h

SRC =	$(SRCDIR)main.c \
		$(SRCDIR)menu.c \
		$(SRCDIR)events.c


all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -I$(INCDIR) -I$(SDLDIR) $(SRC) $(SDL) -o $(NAME)

%.o: %.c $(INC)
	gcc $(FLAGS) -I$(INCDIR) -I$(SDLDIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	gcc $(FLAGS) -I$(INCDIR) -I$(SDLDIR) $(SRC) $(SDL) -o $(NAME)
	./$(NAME)
