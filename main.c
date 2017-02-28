/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:51:32 by maviot            #+#    #+#             */
/*   Updated: 2017/02/27 16:09:12 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
# include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	line = NULL;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	i = 1;
	while (get_next_line(fd, &line) == 1)
	{
		printf("\n | GNL LOOP IN MAIN.C |  line [%d] = [%s]\n\n", i, line);	
		free(line);
		i++;
	}
	if (argc == 2)
		close(fd);
}
