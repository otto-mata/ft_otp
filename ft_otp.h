/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otp.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:50:46 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/01 00:48:13 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OTP_H
# define FT_OTP_H
# include "tiny-AES-c/aes.h"
# include <ctype.h>
# include <errno.h>
# include <fcntl.h>
# include <openssl/evp.h>
# include <openssl/hmac.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_enc_key	t_enc_key;

struct						s_enc_key
{
	unsigned char			*key;
	size_t					key_size;
};

void						main_usage(char const *av0);
void						create_key(char const *fpath);
void						store_key(t_enc_key *key);
t_enc_key					*encrypt_key(char *plain_key);
bool						validate_hexkey(char const *key);
void						generate_otp(char const *key_file);
uint32_t					hotp(uint8_t *key, size_t kl, uint64_t interval);
uint8_t						*hmac_sha1(unsigned char *key, int kl,
								uint64_t interval);
uint32_t					dynamic_truncation(uint8_t *digest);
#endif
