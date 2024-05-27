/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:02:23 by bchene            #+#    #+#             */
/*   Updated: 2023/12/06 16:38:19 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>

typedef struct s_gnlist
{
	char			buffer[BUFFER_SIZE + 1];
	int				nl;
	int				len;
	struct s_gnlist	*next;
}	t_gnlist;

char		*gnl_getlstline(t_gnlist *lst);
int			gnl_lstadd_back(t_gnlist **lst, t_gnlist *node);
t_gnlist	*gnl_lstnew(char *buffer);
void		gnl_lstclear(t_gnlist **lst);

char		*get_next_line(int fd);

#endif
