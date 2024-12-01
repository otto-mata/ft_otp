/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:27:11 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/01 00:27:23 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otp.h"

void	store_key(t_enc_key *key)
{
	int	fd;

	fd = open("./ft_otp.key", O_CREAT | O_RDWR, 0666);
	if (!fd)
		return ((void)fprintf(stderr, "Can't open file \"./ft_otp.key\": %s.\n",
				strerror(errno)));
	if (write(fd, key->key, key->key_size) < 0)
		return ((void)fprintf(stderr, "Error saving key to file: %s.\n",
				strerror(errno)));
}
