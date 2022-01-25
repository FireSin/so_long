NAME = so_long

NAME_BONUS = so_long_bonus

CC = cc

SRCDIR = ./src

SRCDIR_BONUS = ./bonus/src

OBJDIR = ./objs

OBJDIR_BONUS = ./bonus/objs_bonus

HEADDIR = ./includes

HEADDIR_BONUS = ./bonus/includes

FLAGS = -g -fsanitize=address -Wall -Wextra -Werror

HEADER = so_long.h

HEADER_BONUS = so_long_bonus.h

SRC = $(wildcard $(SRCDIR)/*.c)

SRC_BONUS = $(wildcard $(SRCDIR_BONUS)/*_bonus.c)

OBJ = $(addprefix $(OBJDIR)/,$(notdir $(SRC:.c=.o)))

OBJ_BONUS = $(addprefix $(OBJDIR_BONUS)/,$(notdir $(SRC_BONUS:_bonus.c=.o)))

all:    $(NAME)

$(OBJDIR)/%.o :	$(SRCDIR)/%.c $(HEADDIR)/$(HEADER)
	$(CC) $(FLAGS) -I mlx -c $< -o $@

$(NAME):	$(OBJDIR) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -L mlx -l mlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJDIR):
		@if [ ! -d $(OBJDIR) ] ; then echo "creating $(OBJDIR)" ; mkdir $(OBJDIR); fi

bonus:	$(NAME_BONUS)

$(OBJDIR_BONUS)/%.o :	$(SRCDIR_BONUS)/%_bonus.c $(HEADDIR_BONUS)/$(HEADER_BONUS)
	$(CC) $(FLAGS) -I mlx -c $< -o $@

$(NAME_BONUS):	$(OBJDIR_BONUS) $(OBJ_BONUS)
	$(CC) $(FLAGS) $(OBJ_BONUS) -L mlx -l mlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)

$(OBJDIR_BONUS):
		@if [ ! -d $(OBJDIR_BONUS) ] ; then echo "creating $(OBJDIR_BONUS)" ; mkdir $(OBJDIR_BONUS); fi

clean:
		@if [ -d $(OBJDIR) ] ; then echo "deleting $(OBJDIR)" ; rm -r $(OBJDIR); fi

bonus_clean:
		@if [ -d $(OBJDIR_BONUS) ] ; then echo "deleting $(OBJDIR_BONUS)" ; rm -r $(OBJDIR_BONUS); fi

fclean: clean
		rm -f $(NAME)

bonus_fclean: bonus_clean
		rm -f $(NAME_BONUS)

re: fclean all

bonus_re: bonus_fclean bonus

.PHONY: all clean fclean re bonus bonus_clean bonus_fclean bonus_re