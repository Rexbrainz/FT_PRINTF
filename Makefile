# **************************************************************************** #
#                                    FT_PRINT                                  #
# **************************************************************************** #

NAME = libftprintf.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC = ft_printf.c print_char.c print_int.c print_string.c print_unsigned_int.c\
	print_pointer.c	print_hexl.c print_hexu.c
OBJ = $(SRC:.c=.o)

# Bonus source files
#BONUS_SRC = ft_lstadd_back.c	ft_lstiter.c	ft_lstnew.c\
			ft_lstsize.c		ft_lstlast.c	ft_lstclear.c\
			ft_lstadd_front.c	ft_lstdelone.c	ft_lstmap.c
			
BONUS_OBJ = $(BONUS_SRC:.c=.o)

# Commands
all: $(NAME)

# Create the static library
$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

# Compile object files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Bonus target
#bonus: $(BONUS_OBJ)
#	@ar rcs $(NAME) $(BONUS_OBJ)

# Clean object files
clean:
	@rm -f $(OBJ) $(BONUS_OBJ)

# Clean object files and the library
fclean: clean
	@rm -f $(NAME)

# Recompile everything
re: fclean all

# PHONY to avoid confusion
.PHONY: all clean fclean re bonus

