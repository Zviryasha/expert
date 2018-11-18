/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   systemexpert.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:24:49 by opanchen          #+#    #+#             */
/*   Updated: 2018/11/13 14:24:51 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEMEXPERT_H
# define SYSTEMEXPERT_H
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include "get_next_line.h"
# include "libft/libft.h"

int allowedsymbols(char *s);
int checking(int fd);
int redable(char *s);
char  *deletcoment(char *s);
int check_quotes(char *s);
int		chaeck_full(char **s);

#endif
