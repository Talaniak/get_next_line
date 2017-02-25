/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 08:15:48 by maviot            #+#    #+#             */
/*   Updated: 2017/01/14 01:13:26 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		len_n(char *s)
{
	int				i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}

static int		ft_build_line(int const fd, char **line, char **stock)
{
	int				bytes;
	char			*buf;
	char			*build;

	buf = ft_strnew(BUFF_SIZE);
	if ((bytes = read(fd, buf, BUFF_SIZE)) <= 0)
	{
		free(buf);
		return (bytes);
	}
	build = ft_strsub(buf, 0, len_n(buf));
	if (build[ft_strlen(build) - 1] == '\n')
		*stock = ft_strsub(buf, len_n(buf), ft_strlen(buf));
	if (*line == NULL)
		*line = build;
	else
	{
		*line = ft_strjoin(*line, build);
		free(build);
	}
	free(buf);
	return (bytes);
}

static int		ft_check_stock(char **stock, char **line)
{
	char			*build;
	int				booln;

	booln = 0;
	if (*stock != NULL)
	{
		build = ft_strsub(*stock, 0, len_n(*stock));
		if (build[ft_strlen(build) - 1] == '\n')
		{
			*stock = ft_strsub(*stock, len_n(*stock),
					(ft_strlen(*stock) - len_n(*stock)));
			booln = 1;
		}
		else
		{
			free(*stock);
			*stock = NULL;
		}
		*line = ft_strsub(build, 0, ft_strlen(build) - booln);
		free(build);
	}
	else
		*line = NULL;
	return (booln);
}

int				get_next_line(int const fd, char **line)
{
	int				bytes;
	int				foundn;
	int				reading;
	static char		*stock[4096];

	if (fd < 0)
		return (-1);
	if (line == NULL)
		return (-1);
	if ((ft_check_stock(&stock[fd], line)) == 1)
		return (1);
	foundn = 0;
	reading = 0;
	while (foundn != 1)
	{
		if ((bytes = ft_build_line(fd, line, &stock[fd])) <= 0)
		{
			if (reading == 1)
				return (1);
			if ((reading != 1) && (*line != NULL) && (*line[0] != '\0'))
				return (1);
			else
				return (bytes);
		}
		reading = 1;
		if (line[0][ft_strlen(*line) - 1] == '\n')
		{
			foundn = 1;
			line[0][ft_strlen(*line) - 1] = '\0';
		}
	}
	return (1);
}
