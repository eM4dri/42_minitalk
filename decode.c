/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 22:55:43 by emadriga          #+#    #+#             */
/*   Updated: 2021/09/05 22:55:45 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int		i;
	int		input[8];
	char	str;

	str = 0;
	input[0] = 0;
	input[1] = 1;
	input[2] = 0;
	input[3] = 0;
	input[4] = 1;
	input[5] = 0;
	input[6] = 0;
	input[7] = 0;
	i = 0;
	while (i < 8)
	{
		if (input[i])
			str = str | 1;
		printf("\t%d\t%d\n", i, input[i]);
		str <<= 1;
		i++;
		printf("%x\n", str);
	}
	printf("%x", str);
}
