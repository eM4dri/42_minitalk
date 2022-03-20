/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 22:54:16 by emadriga          #+#    #+#             */
/*   Updated: 2021/09/05 22:54:17 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	*str;
	int		i;

	str = "Hello world";
	while (*str != '\0')
	{
		i = 8;
		while (i--)
		{
			printf("%d", (*str >> i) & 1);
		}
		str++;
		printf("\n");
	}
}
