# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 17:50:53 by mstrauss          #+#    #+#              #
#    Updated: 2024/04/23 16:56:49 by mstrauss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server
SRCS_SERVER= $(addprefix $(SRC_DIR)/, server.c utils.c)
SRCS_CLIENT= $(addprefix $(SRC_DIR)/, client.c utils.c)

NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus
SRCS_SERVER_BONUS = $(addprefix $(SRC_DIR)/, server_bonus.c utils.c)
SRCS_CLIENT_BONUS = $(addprefix $(SRC_DIR)/, client_bonus.c utils.c)

OBJS_CLIENT = $(SRCS_CLIENT:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_SERVER = $(SRCS_SERVER:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

CC = cc

CFLAGS			= -Wall -Werror -Wextra -O3 #-lm
DEBUG_FLAGS 	= -g -fsanitize=address -fcolor-diagnostics -fansi-escape-codes
VALGRIND_FLAGS 	= -g

LIBFT_DIR 	=	./libft
BUILD_DIR 	=	./build
SRC_DIR 	=	./src
BIN_DIR 	=	./bin

LIBFT       =	$(BIN_DIR)/libft.a
LIBFT_DBG	=	$(BIN_DIR)/libft_dbg.a


all: $(BIN_DIR) $(BUILD_DIR) $(LIBFT) ${NAME_CLIENT} ${NAME_SERVER}

bclient: $(BIN_DIR) $(BUILD_DIR) $(LIBFT) ${NAME_CLIENT}
bserver: $(BIN_DIR) $(BUILD_DIR) $(LIBFT) ${NAME_SERVER}

bclient_bonus: $(BIN_DIR) $(BUILD_DIR) $(LIBFT) ${NAME_CLIENT_BONUS}
bserver_bonus: $(BIN_DIR) $(BUILD_DIR) $(LIBFT) ${NAME_SERVER_BONUS}

bonus: $(BIN_DIR) $(BUILD_DIR) $(LIBFT) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)
# mv ${NAME_CLIENT_BONUS} ./client_bonus # remove these lines to remove relinking
# mv ${NAME_SERVER_BONUS} ./server_bonus #

debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(BIN_DIR) $(BUILD_DIR) $(LIBFT_DBG) $(OBJS_CLIENT) $(OBJS_SERVER) 
	${CC} ${CFLAGS} -o ${NAME_CLIENT} $(OBJS_CLIENT) $(LIBFT_DBG) 
	${CC} ${CFLAGS} -o ${NAME_SERVER} $(OBJS_SERVER) $(LIBFT_DBG) 

${NAME_CLIENT}: $(OBJS_CLIENT)
	${CC} ${CFLAGS} -o ${NAME_CLIENT} $(OBJS_CLIENT) $(LIBFT) 

${NAME_SERVER}: $(OBJS_SERVER)
	${CC} ${CFLAGS} -o ${NAME_SERVER} $(OBJS_SERVER) $(LIBFT) 

${NAME_CLIENT_BONUS}: $(OBJS_CLIENT_BONUS)
	${CC} ${CFLAGS} -o ${NAME_CLIENT_BONUS} $(OBJS_CLIENT_BONUS) $(LIBFT) 

${NAME_SERVER_BONUS}: $(OBJS_SERVER_BONUS)
	${CC} ${CFLAGS} -o ${NAME_SERVER_BONUS} $(OBJS_SERVER_BONUS) $(LIBFT) 

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)
	
$(LIBFT_DBG):
	make -C $(LIBFT_DIR) debug

$(BIN_DIR) $(BUILD_DIR):
	mkdir -p $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS_CLIENT)
	rm -f $(OBJS_SERVER)
	rm -f $(OBJS_CLIENT_BONUS)
	rm -f $(OBJS_SERVER_BONUS)
    
fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f ${NAME_CLIENT}
	rm -f ${NAME_SERVER}
	rm -f ${NAME_CLIENT_BONUS}
	rm -f ${NAME_SERVER_BONUS}
	rm -f ${LIBFT_DBG}

re: fclean all

.PHONY: clean fclean all debug re bonus