/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_usage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:58:01 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/30 22:25:40 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otp.h"

void	main_usage(char const *av0)
{
	printf("Usage: %s -g <hexadecimal key> | -k <file.key>\n", av0);
	printf("\t-g <key>\t\tEncrypt and stores 'key' in 'ft_otp.key'.\n");
	printf("\t-k <file.key>\t\tGenerates a temporary password using 'file.key'.\n");
}
