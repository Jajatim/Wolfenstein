# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: sifouche <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/12/07 15:32:55 by sifouche     #+#   ##    ##    #+#        #
#    Updated: 2019/04/18 13:32:02 by sifouche    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = a.out
SRC = a.c


all: $(NAME)

$(NAME): $(OBJ)
	gcc -Wall -Wextra $(SRC) -F . -framework SDL2 -rpath .
	#echo "Tabarnak, personne a code le Makefile"

%.o: %.c $(H_FILES)
	gcc $(FLAGS) -c $< -o $@

clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

test:
	gcc -Wall -Wextra $(SRC) -F . -framework SDL2 -rpath .
	./a.out
