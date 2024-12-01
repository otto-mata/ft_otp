/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_truncation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:35:42 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/01 00:36:12 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otp.h"

uint32_t	dynamic_truncation(uint8_t *digest)
{
	uint64_t	offset;
	uint32_t	bin_code;

	offset = digest[19] & 0x0f;
	bin_code = (digest[offset] & 0x7f) << 24 | (digest[offset
			+ 1] & 0xff) << 16 | (digest[offset
			+ 2] & 0xff) << 8 | (digest[offset + 3] & 0xff);
	return (bin_code);
}