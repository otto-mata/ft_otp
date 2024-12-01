/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:27:43 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/01 00:54:04 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otp.h"

t_enc_key	*decrypt_key(unsigned char *key)
{
	unsigned char const	enc_key[] = "rGBr73k?C6pGrSbHcjfe#AeSAayaQ5Mz";
	unsigned char const	iv[] = {
		0xf0, 0xf1, 0xf2, 0xf3, 0xf4,
		0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
	};
	struct AES_ctx		ctx;
	t_enc_key			*uc_key;
}
