/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 22:54:13 by emadriga          #+#    #+#             */
/*   Updated: 2021/09/11 15:37:57 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_men	g_men;

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

static void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

static void	ft_putnbr(int n)
{
	unsigned int	un;

	if (n < 0)
	{
		un = (unsigned int) n * -1;
		ft_putchar('-');
	}
	else
		un = (unsigned int) n;
	if (un >= 10)
	{
		ft_putnbr(un / 10);
		ft_putnbr(un % 10);
	}
	else
		ft_putchar(un + '0');
}

static void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		g_men.msg |= 1;
	g_men.pos++;
	if (g_men.pos < 8)
		g_men.msg <<= 1;
	else
	{
		if (g_men.msg == 0)
			write(STDOUT_FILENO, ROGER, ft_strlen(ROGER));
		else
			ft_putchar(g_men.msg);
		g_men.msg = 0;
		g_men.pos = 0;
	}
}

int	main(void)
{
	write(1, "PID:\t", 6);
	ft_putnbr(getpid());
	write(STDOUT_FILENO, "\n", 1);
	g_men.msg = 0;
	g_men.pos = 0;
	signal(SIGUSR1, &signal_handler);
	signal(SIGUSR2, &signal_handler);
	write(STDOUT_FILENO, READY, ft_strlen(READY));
	while (1)
		pause();
}
