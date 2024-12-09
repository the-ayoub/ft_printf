# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aybelhaj <aybelhaj@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 21:50:13 by aybelhaj          #+#    #+#              #
#    Updated: 2024/12/09 20:28:40 by aybelhaj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
AR		=	ar
ARFLAGS	=	-rcs
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

OBJDIR	=	build
SRCS	=	ft_printf.c ft_printf_utils.c ft_printf_ptr.c
OBJS	=	$(addprefix $(OBJDIR)/, ${SRCS:.c=.o})
LIBFT_PATH	=	./libft
LIBFT		=	$(LIBFT_PATH)/libft.a

PURPLE	=	\033[0;35m
BLUE	=	\033[0;34m
RESET	=	\033[m

all: $(NAME)

$(LIBFT):
	@printf "%-42b%b" "$(PURPLE)$(*F):" "$(BLUE)$(@)$(RESET)\n"
	@make -C $(LIBFT_PATH) --silent

$(OBJS): $(OBJDIR)/%.o : %.c ft_printf.h | $(OBJDIR)
	@printf "%-42b%b" "$(PURPLE)$(<):" "$(BLUE)$(@F)$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir $(OBJDIR)

$(NAME): $(OBJS) $(LIBFT)
	@printf "%-42b%b" "$(PURPLE)$(*F):" "$(BLUE)$(@)$(RESET)\n"
	@cp $(LIBFT) $@
	@$(AR) $(ARFLAGS) $@ $^

fclean: clean
	@printf "%b" "$(BLUE)$(@)ing...$(RESET)\n"
	@make $@ -C $(LIBFT_PATH) --silent
	@rm -rf $(NAME)

clean:
	@printf "%b" "$(BLUE)$(@)ing...$(RESET)\n"
	@make $@ -C $(LIBFT_PATH) --silent
	@rm -rf $(OBJDIR)

re:    fclean all

.PHONY: all clean fclean re $(LIBFT)
