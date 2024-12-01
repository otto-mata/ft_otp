/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_hexkey.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:28:07 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/01 00:28:15 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otp.h"

bool	validate_hexkey(char const *key)
{
	off_t	i;

	i = 0;
	while (key[i])
	{
		if (!isxdigit(key[i]))
			return (false);
		i++;
	}
	return (true);
}
