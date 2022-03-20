/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 22:54:47 by emadriga          #+#    #+#             */
/*   Updated: 2021/09/11 15:37:16 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

static int	valid_pid(const char *str)
{
	int	pid;

	pid = 0;
	while (*str != '\0' && pid < PIDMAX)
	{
		if (*str >= '0' && *str <= '9')
			pid = pid * 10 + *str - '0';
		else
			return (0);
		str++;
	}
	if (pid < PIDMIN || pid > PIDMAX)
		return (0);
	else
		return (1);
}

static int	ft_atoi(const char *str)
{
	int				sign;
	long long		result;

	sign = 1;
	result = 0;
	while (*str != 0 && (*str == 32 || (*str >= 9 && *str <= 13)))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	while (*str >= '0' && *str <= '9' && result < 2147483648)
		result = 10 * result + (int)(*str++ - '0');
	if (result > 2147483647 && sign > 0)
		return (-1);
	if (result > 2147483648 && sign < 0)
		return (0);
	return ((int)result * sign);
}

static void	ft_code(char *str, int pid)
{
	int		i;

	while (*str != '\0')
	{
		i = 8;
		while (i--)
		{
			if ((*str >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
		}
		str++;
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep(50);
	}
	write(1, OVER, ft_strlen(OVER));
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = 0;
	if (argc == 3)
	{
		if (!valid_pid(argv[1]))
		{
			write(STDOUT_FILENO, WRONGPID, ft_strlen(WRONGPID));
			return (EINVAL);
		}
		pid = ft_atoi(argv[1]);
		ft_code(argv[2], pid);
	}
	else
	{
		write(STDOUT_FILENO, WRONGARGCS, ft_strlen(WRONGARGCS));
		return (EINVAL);
	}
	return (0);
}
