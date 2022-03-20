/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 22:54:10 by emadriga          #+#    #+#             */
/*   Updated: 2021/09/11 15:28:21 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <errno.h>
# define PIDMIN	100
# define PIDMAX	99998
# define WRONGPID "Error wrong PID"
# define WRONGARGCS "Input error\nExample of use: './client pid message'\n"
# define OVER "Message send!\n"
# define READY "Server listening...\n"
# define ROGER "\nMessage received!\n"

typedef struct s_men
{
	int	msg;
	int	pos;
}t_men;
#endif