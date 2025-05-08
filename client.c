/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kato <kato@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:44:22 by kato              #+#    #+#             */
/*   Updated: 2025/05/08 16:28:55 by kato             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

static void	send_bit(int pid, char bit)
{
	if (bit == '1')
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_putstr("Error: Failed to send signal\n");
			exit(1);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_putstr("Error: Failed to send signal\n");
			exit(1);
		}
	}
	usleep(100);
}

static void	send_char(int pid, char c)
{
	int		i;
	char	bit;

	i = 7;
	while (i >= 0)
	{
		bit = ((c >> i) & 1) + '0';
		send_bit(pid, bit);
		i--;
	}
}

static void	send_string(int pid, char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr("Error: Invalid arguments\n");
		return (1);
	}
	pid = atoi(argv[1]);
	if (pid <= 0)
	{
		ft_putstr("Error: Invalid PID\n");
		return (1);
	}
	send_string(pid, argv[2]);
	return (0);
}
