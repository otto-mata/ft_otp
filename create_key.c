/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:26:44 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/01 00:29:55 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otp.h"

void	create_key(char const *fpath)
{
	int				fd;
	struct stat		st;
	long			rdsz;
	char			*filecontent;
	t_enc_key		*enc;

	fd = open(fpath, O_RDONLY);
	fstat(fd, &st);
	rdsz = st.st_size;
	if (rdsz < 64)
		return ((void)fprintf(stderr,
				"create_key: Key must be at least 64 characters long.\n"));
	filecontent = calloc(rdsz + 1, sizeof(char));
	if (!filecontent)
		return ((void)fprintf(stderr, "create_key: Allocation error.\n"));
	if (read(fd, filecontent, rdsz) < 0)
		return ((void)fprintf(stderr, "create_key: Read error.\n"));
	if (!validate_hexkey(filecontent))
		return ((void)fprintf(stderr,
				"create_key: Key must only contain hexadecimal characters.\n"));
	enc = encrypt_key(filecontent);
	store_key(enc);
	fprintf(stdout, "Key was successfully saved in ft_otp.key.\n");
}
