/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:30:29 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/01 00:43:10 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otp.h"

uint32_t	hotp(uint8_t *key, size_t kl, uint64_t interval)
{
	uint8_t		*digest;
	uint32_t	result;
	uint32_t	endianness;
	uint32_t	dbc;

	endianness = 0xCAFEBABE;
	if ((*(const uint8_t *)&endianness) == 0xBE)
	{
		interval = ((interval & 0X00000000FFFFFFFF) << 32)
			| ((interval & 0XFFFFFFFF00000000) >> 32);
		interval = ((interval & 0X0000FFFF0000FFFF) << 16)
			| ((interval & 0XFFFF0000FFFF0000) >> 16);
		interval = ((interval & 0X00FF00FF00FF00FF) << 8)
			| ((interval & 0XFF00FF00FF00FF00) >> 8);
	}
	digest = (uint8_t *)hmac_sha1(key, kl, interval);
	dbc = dynamic_truncation(digest);
	result = dbc % 1000000;
	return (result);
}
