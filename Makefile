# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 07:56:24 by hkumagai          #+#    #+#              #
#    Updated: 2022/09/13 06:58:40 by hkumagai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
# -fsanitize=address
ARFLAGS := -rcs
INCLUDE = -I./include
LDFLAGS = -Llib/ft_printf -Llib/libft
LIBS = -lftprintf -lft

SRCS_DIR := ./src
SRCS_DIR/ := $(if $(SRCS_DIR),$(patsubst %//,%/,$(SRCS_DIR)/),)
SRCS := $(addprefix $(SRCS_DIR/), push_swap.c free.c check_args.c stack.c sort.c)

COMMAND_SRCS_DIR := ./src/command
COMMAND_SRCS_DIR/ := $(if $(COMMAND_SRCS_DIR),$(patsubst %//,%/,$(COMMAND_SRCS_DIR)/),)
COMMAND_SRCS := $(addprefix $(COMMAND_SRCS_DIR/),sa.c sb.c ss.c push.c ra.c rb.c rr.c rra.c rrb.c rrr.c)

OBJS_DIR := ./objs
OBJS_DIR/ := $(if $(OBJS_DIR),$(patsubst %//,%/,$(OBJS_DIR)/),)
OBJS := $(SRCS:$(SRCS_DIR/)%.c=$(OBJS_DIR/)%.o)
COMMAND_OBJS :=$(COMMAND_SRCS:$(COMMAND_SRCS_DIR/)%.c=$(OBJS_DIR/)%.o)

OUTPUT_DIR := .
OUTPUT_DIR/ := $(if $(OUTPUT_DIR),$(patsubst %//,%/,$(OUTPUT_DIR)/),)

LIB_DIR := ./lib
LIB_DIR/ := $(if $(LIB_DIR),$(patsubst %//,%/,$(LIB_DIR)/),)

all: libMake ${NAME}

${NAME}: $(OBJS) $(COMMAND_OBJS) $(OUTPUT_DIR/).keep
	$(CC) $(CFLAGS) ${INCLUDE} $(OBJS) $(COMMAND_OBJS) ${LDFLAGS} ${LIBS} -o $(NAME)

clean:
	make clean -C ./lib/libft
	make clean -C ./lib/ft_printf
	rm -rf ${OBJS_DIR} $(OUTPUT_DIR/).keep

fclean: clean
	make fclean -C ./lib/libft
	make fclean -C ./lib/ft_printf
	rm -rf ${NAME}

re: fclean all

libMake: $(OBJS_DIR/).keep libft ft_printf

libft: $(LIB_DIR/)libft/libft.a

$(LIB_DIR/)libft/libft.a:
	make -C ./lib/libft

ft_printf: $(LIB_DIR/)ft_printf/libftprintf.a

$(LIB_DIR/)ft_printf/libftprintf.a:
	make -C ./lib/ft_printf

$(OBJS_DIR/)%.o: $(SRCS_DIR/)%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(COMMAND_OBJS): $(OBJS_DIR/)%.o: $(COMMAND_SRCS_DIR/)%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJS_DIR/).keep $(OUTPUT_DIR/).keep:
	mkdir -p $(@D)
	touch $@

test: all
	@./${NAME}

.PHONY: all clean fclean re test
