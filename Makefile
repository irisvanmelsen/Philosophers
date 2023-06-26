# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 10:12:14 by ivan-mel          #+#    #+#              #
#    Updated: 2023/06/26 15:20:30 by ivan-mel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	philo

#UTILS
FLAGS 		=	-Wall -Werror -Wextra
CC 			= 	gcc
RM 			=	rm -rf
AR			=	ar -rc
SRC			=	main.c \
				check.c \
				error.c \
				mutex.c \
				initialise.c \
				initialise_utils.c

ifdef DEBUG
	FLAGS += -g
endif

#OBJB_FILES	=	${SRCB:.c=.o}
OBJ_DIR		:=	./obj
SRC_DIR 	:= 	./src

# Reset
Color_Off	=	"\033[0m"			# Text Reset

# Regular Colors
Black		=	"\033[0;30m"		# Black
Red			=	"\033[0;31m"		# Red
Green		=	"\033[0;32m"		# Green
Yellow		=	"\033[0;33m"		# Yellow
Blue		=	"\033[0;34m"		# Blue
Purple		=	"\033[0;35m"		# Purple
Cyan		=	"\033[0;36m"		# Cyan
White		=	"\033[0;37m"		# White

# Avoid relinking in bonus
ifdef WITH_BONUS
	OBJ_RAW = $(OBJ_FILES) $(OBJB_FILES)
else
	OBJ_RAW = $(OBJ_FILES)
endif

# Add obj / src directory to obj / src path
OBJ		:= 	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
SRC		:=	$(addprefix $(SRC_DIR)/,$(SRC))

all:	${NAME}

${NAME}: ${OBJ}
	@echo ${Blue} Building ${NAME} ${Color_Off}
	@${CC} ${OBJ} -o ${NAME}
	@echo ${Green} Complete 😊 ${Color_Off}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
# @mkdir -p ${OBJ_DIR}
	@echo ${Blue} Compiling: $< ${Color_Off}
	@${CC} ${FLAGS} -c $< -o $@

$(OBJ_DIR):
	@mkdir $@

# Set 'WITH_BONUS' option to make with bonus
#bonus:
#	@$(MAKE) WITH_BONUS=true all

clean:
	@echo ${Yellow} Deleting ${OBJ_DIR} ${Color_Off}
	@${RM} ${OBJ_DIR}
fclean: clean
	@echo ${Yellow} Deleting ${NAME} ${Color_off}
	@${RM} ${NAME}
	
re:	fclean all

.PHONY: all bonus clean fclean re
