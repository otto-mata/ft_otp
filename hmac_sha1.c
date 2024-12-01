/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmac_sha1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:34:50 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/01 00:35:02 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otp.h"

uint8_t	*hmac_sha1(unsigned char *key, int kl, uint64_t interval)
{
	return ((uint8_t *)HMAC(EVP_sha1(), key, kl,
			(const unsigned char *)&interval, sizeof(interval), NULL, 0));
}
