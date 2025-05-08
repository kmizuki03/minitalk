/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kato <kato@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:47:40 by kato              #+#    #+#             */
/*   Updated: 2025/05/08 16:29:08 by kato             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int	bit_count = 0;
	static char	c = 0;

	(void)context;
	(void)info;
	if (sig == SIGUSR1)
		c |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		bit_count = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	write(1, "Server PID: ", 12);
	ft_putnbr(pid);
	write(1, "\n", 1);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) ==
		-1)
	{
		write(2, "Error: Signal handling failed\n", 30);
		return (1);
	}
	while (1)
		pause();
	return (0);
}
