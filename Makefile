NAME = lem-in

PATHTOMAKEFILE = ./libft/

FILE =	error \
		lem_in \
		links \
		read \
		rooms \
		algo \
		algo_utilit \
		utilities

OBJ  := $(addsuffix .o, $(FILE))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "----------------------------------------"
	@echo "|       Debut de la compilation        |"
	@echo "|              Ecole 42                |"
	@echo "|               Lem-in                 |"
	@echo "|           sub compilation :          |"
	@echo "|               libft                  |"
	@make -C $(PATHTOMAKEFILE)
	@gcc -o $(NAME) -Wall -Werror -O3 -L ./libft/ -lft -Wextra -g $(OBJ)
	@echo "|                 FIN                  |"
	@echo "----------------------------------------"
	@echo "               ________"
	@echo "          _,.-Y  |  |  Y-._"
	@echo "      .-~\"   ||  |  |  |   \"-."
	@echo "      I\" \"\"==\"|\" !\"\"! \"|\"[]\"\"|     _____"
	@echo "      L__  [] |..------|:   _[----I\" .-{\"-."
	@echo "     I___|  ..| l______|l_ [__L]_[I_/r(=}=-P"
	@echo "    [L______L_[________]______j~  '-=c_]/=-^"
	@echo "     \_I_j.--.\==I|I==_/.--L_]"
	@echo "       [_((==)[\`-----\"](==)j"
	@echo "          I--I\"~~\"\"\"~~\"I--I"
	@echo "          |[]|         |[]|"
	@echo "          l__j         l__j"
	@echo "          |!!|         |!!|"
	@echo "          |..|         |..|"
	@echo "          ([])         ([])"
	@echo "          ]--[         ]--["
	@echo "          [_L]         [_L]"
	@echo "         /|..|\       /|..|\\ "
	@echo "        \`=}--{='     \`=}--{=i'"
	@echo "       .-^--r-^-.   .-^--r-^-."
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"

$(OBJ): %.o: %.c
	@gcc -c -Wall -Wextra -Werror -g $< -o $@

clean:
	@rm -rf $(OBJ)
	@make -C $(PATHTOMAKEFILE) clean
fclean: clean
	@rm -rf $(NAME)
	@make -C $(PATHTOMAKEFILE) fclean

re: fclean all

.PHONY : all clean fclean re