/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encrypt_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:27:43 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/01 00:27:51 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otp.h"

t_enc_key	*encrypt_key(char *plain_key)
{
	unsigned char const	enc_key[] = "rGBr73k?C6pGrSbHcjfe#AeSAayaQ5Mz";
	unsigned char const	iv[] = {
		0xf0, 0xf1, 0xf2, 0xf3, 0xf4,
		0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
	};
	size_t const		plain_sz = strlen(plain_key);
	struct AES_ctx		ctx;
	t_enc_key			*uc_key;

	uc_key = calloc(1, sizeof(t_enc_key));
	if (!uc_key)
		return (0);
	uc_key->key_size = 64;
	uc_key->key = calloc(uc_key->key_size, sizeof(unsigned char));
	if (!uc_key->key)
		return (0);
	memcpy(uc_key->key, plain_key, plain_sz);
	AES_init_ctx_iv(&ctx, enc_key, iv);
	AES_CTR_xcrypt_buffer(&ctx, uc_key->key, plain_sz);
	return (uc_key);
}
