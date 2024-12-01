/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:16:43 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/01 00:47:46 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otp.h"


int	main(int argc, char const *argv[])
{
	int	mode;

	mode = 0;
	if (argc != 3)
		return (main_usage(argv[0]), 1);
	if (strcmp(argv[1], "-g") == 0)
		mode = 1;
	else if (strcmp(argv[1], "-k") == 0)
		mode = 2;
	if (!mode)
	{
		fprintf(stderr, "Unrecognized option \"%s\".\n", argv[1]);
		main_usage(argv[0]);
		return (1);
	}
	if (access(argv[2], R_OK) < 0)
		return (fprintf(stderr, "Can't open file \"%s\": %s.\n", argv[2],
				strerror(errno)), 1);
	if (mode == 1)
		create_key(argv[2]);
	else
		generate_otp(argv[2]);
	return (0);
}
