/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maviot <maviot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:21:15 by maviot            #+#    #+#             */
/*   Updated: 2016/12/07 02:48:22 by maviot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	if ((ft_isalpha(c) == 1) || (ft_isdigit(c) == 1))
		return (1);
	else
		return (0);
}
