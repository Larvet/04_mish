# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchene <bchene@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 16:18:12 by bchene            #+#    #+#              #
#    Updated: 2024/05/23 13:55:34 by bchene           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		minishell

SRCS_DIR =	./srcs
OBJS_DIR =	./objs

CC = 		cc
CFLAGS = 	-Wall -Wextra -Werror -g

HEADERS = 	-I ./includes -I ./libs/libft
LIBS = 		./libs/libft/libft.a

# ls -1 *.c | sed -z 's/\n/ \\\n\t\t\t/g'
SRCS =		lo_check_open_quotes.c \
			lo_check_syntax_error.c \
			lo_check_unhandled.c \
			lo_handle_word.c \
			lo_mish_check_line.c \
			lo_mish_split.c \
			lo_remove_quotes.c \
			lo_set_processes.c \
			lo_signals.c \
			lo_ft_strjoin_tab.c \
			lo_strtab.c \
			lo_strtab_if.c \
			lo_substitute_2.c \
			lo_substitute.c \
			lo_substitute_vars.c \
			lo_t_process_split.c \
			mish_00_main.c \
			mish_01_mish_00.c \
			mish_01_mish_01_error.c \
			mish_01_mish_02_prompt.c \
			mish_01_mish_03_line.c \
			mish_01_mish_04_splitline.c \
			mish_01_mish_05_p.c \
			mish_01_mish_06_fds.c \
			mish_01_mish_07_pid.c \
			mish_01_mish_08_env.c \
			mish_01_mish_09_unset.c \
			mish_01_mish_10_env_unset.c \
			mish_01_mish_11_exit_status.c \
			mish_01_mish_12_pathlist.c \
			mish_02_t_error_00.c \
			mish_02_t_error_01.c \
			mish_03_t_env_00.c \
			mish_03_t_env_01.c \
			mish_50_process.c \
			mish_51_process_iofiles_00.c \
			mish_51_process_iofiles_01.c \
			mish_52_process_cmd.c \
			mish_53_process_exec.c \
			mish_54_process_pipe.c \
			mish_60_t_file.c \
			mish_61_p_files_open.c \
			mish_62_p_files_close.c \
			mish_63_p_files_heredoc.c \
			mish_70_builtin.c \
			mish_71_builtin_echo.c \
			mish_72_builtin_cd.c \
			mish_73_builtin_pwd.c \
			mish_74_builtin_export.c \
			mish_75_builtin_unset.c \
			mish_76_builtin_env.c \
			mish_77_builtin_exit.c \
			mish_78_builtin_nocmd_noaccess.c \
			mish_79_builtin_pmish_pes.c \
			mish_90_ft_strjoin_va.c \
			mish_91_ft_00.c \
			mish_91_ft_01.c

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all: libft $(NAME)
	@echo "\001\e[1;32m\002Compilation OK \001\e[0m\002"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@test -d $(OBJS_DIR) || mkdir $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(NAME): $(OBJS)
	@echo "\001\e[1;32m\002Compiling minishell \001\e[0m\002"
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) -lreadline

# make libft.a	
libft:
	@make --no-print-directory -C ./libs/libft -s

# make and gdb
gdb: all
	@gdb -tui $(NAME)

# make and vallgrind
valgrind: all
	@clear
	@valgrind --show-leak-kinds=all --leak-check=full --track-origins=yes --track-fds=yes --suppressions=vsupp ./$(NAME)

# make and run
run: all
	@clear
	@./$(NAME)

# clean libs and objects
clean:
	@rm -rf $(OBJS_DIR)
	@make --no-print-directory -C ./libs/libft clean -s

# clean everythings done
fclean: clean
	@rm -rf $(NAME)

# clean then make
re: clean all

.PHONY: all, clean, fclean, re, libft, gdb, valgrind, run
