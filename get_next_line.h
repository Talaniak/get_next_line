/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 02:10:23 by maviot            #+#    #+#             */
/*   Updated: 2017/01/14 01:07:47 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 8000

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // !!! A DELETE !!!

int		get_next_line(const int fd, char **line);

#endif
