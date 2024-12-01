/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:49:25 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/01 00:49:59 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otp.h"

uint32_t	totp(uint8_t *key, size_t kl, uint64_t time)
{
	uint32_t	totp;

	totp = hotp(key, kl, time);
	return (totp);
}
