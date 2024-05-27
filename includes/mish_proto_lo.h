/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_proto_lo.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:11:01 by bchene            #+#    #+#             */
/*   Updated: 2024/05/27 17:26:24 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISH_PROTO_LO_H
# define MISH_PROTO_LO_H

/* check_syntaxe_error */
int		ft_isspace(char c); /////////// lib
int		mish_check_syntax_error(t_mish *mish);
//int		mish_check_open_quotes(t_mish *mish);

/* check_open_quotes */
int		mish_check_open_quotes(t_mish *mish);

/* check_unhandled */
int		is_between_quotes(char *str, int i);
int		mish_check_unhandled(t_mish *mish);

/* fill_processes */
void	file_add_back(t_file **lst, t_file *new);

/* handle word */
int		handle_quotes(char *str, int i, char q);
int		handle_redirections(char *str, int i, char r);
int		handle_specials(char *str, int i);
int		handle_word(char *str, char *sep, int i);

/* parsing */
int		mish_parsing(t_mish *mish);

/* mish_split */
// int	m_count_words(char *str, char c);
// char	*str_piece_cpy(char *s, int start, int end);
// char	*from_str_to_strs(char *s, int *i, char c);
// void	free_all(char **split, int nbr_str);
char	**mish_split(char *s, char c);

/* t_process_split */
int		count_words(char *str, char *sep);
char	**t_process_split(t_process *p, char *sep);

/* substitute vars */
int		is_there_a_var(char *str);
char	*get_var_value(t_mish *mish, char *var);
char	*substitute_hub(t_mish *mish, char *src, char *var);
void	mish_var_dup(t_mish *mish, char **line, char *var);
void	mish_substitute_vars(t_mish *mish, char **p_lines);
//void	mish_remove_quotes(t_mish *mish, char **p_lines); // obsolete

/* mish_remove_quotes */
// char *quotes_strchr(char *str);
// char *copy_removing(char *dst, char *src, char *start, char *end);
t_err_type  mish_remove_quotes(t_mish *mish, char **p_lines);

/* substitute vars */
char	*copy_sub(char *dst, char *src, char *var, char *sub);
char	*dup_substituting(char *src, char *var, char *sub);
char	*substitute_0(t_mish *mish, char *src, char *var);
char	*substitute_exit_status(t_mish *mish, char *src, char *var);
char	*substitute_var(t_mish *mish, char *src, char *var);

/* lo_substitute_2 */
char    *mish_substitute_str(t_mish *mish, int f(char *, int), char *str);
char    **mish_substitute_strtab(t_mish *mish, int f(char *, int), char **strtab);

/* lo_set_processes */
t_tfile_type	t_file_line_get_type(char *line);
char			*t_file_line_get_path(char *line);
//void			t_process_t_file_set(t_process *p, char **iofiles);
//void			t_process_args_set(t_process *p, char **args);
//void          t_process_iofiles_args_set(t_process *p, char **iofiles, char **args);
void			t_process_set(t_process *p);

/* lo_strtab_if */
// int  strtab_count_if(char **split, t_tfile_type f(char *), int b);
// int  strtab_set_if(char **dst, char **src, t_tfile_type f(char *), int b);
char    **strtab_dup_if(char **src, t_tfile_type f(char *), int b);

/* ft_strjoin_tab */
size_t  ft_strlen_tab(char **strtab);
char    *ft_strcpy_tab(char *dst, char **srcs, char sep);
char    *ft_strjoin_tab(char **strtab, char sep);

/* lo_mish_parse_line.c */
t_err_type  mish_first_substitution(t_mish *mish);
t_err_type  mish_check_line(t_mish *mish);
// t_err_type  mish_parse_process_line(t_mish *mish);

/* lo_strtab.c */
char	**strtab_addstr(char **strtab, char *str);
void	strtab_print(char **strtab, char *sep);

/* lo_signals.c */
void	init_sa(t_sa *sa, void handler(int, siginfo_t *, void *));
void    handle_signal(int sig, siginfo_t *info, void *ucontext);

//////////////////////////
/*			zz			*/

/* fill process */
// int		mish_fill_processes(t_mish *mish);

/* separate processes */
// void	process_init_line(t_process **p, char **split, int count);
// void	mish_init_p_mish(t_mish *mish);
// int		mish_separate_processes(t_mish *mish);

/* lo_print */
// void	print_process_lines(t_process *p, int count);
// void	print_files(t_file *lst);
// void	print_split(char **split);
// void	mish_print_processes(t_mish *mish);

#endif
