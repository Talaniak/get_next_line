/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:26:34 by maviot            #+#    #+#             */
/*   Updated: 2017/03/02 07:46:34 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = 0;
	len = (ft_strlen(s1) + ft_strlen(s2));
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[++i])
		ret[i] = s1[i];
	while (s2[j])
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	free((void *)s1);
	free((void *)s2);
	ret[i] = '\0';
	return (ret);
}
