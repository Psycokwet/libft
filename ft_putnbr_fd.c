/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 20:32:49 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	ft_putnbr_fd_int(int n, int fd)
{
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putnbr_fd_int(n / 10, fd);
		ft_putnbr_fd_int(n % 10, fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n - 1 > 0)
		{
			ft_putnbr_fd_int((-(n + 1) / 10), fd);
			ft_putnbr_fd_int((-((n + 1) % 10) + 1), fd);
		}
		else
			ft_putnbr_fd_int(-n, fd);
	}
	else
		ft_putnbr_fd_int(n, fd);
}
/*
** #1. L'integer à ecrire.
** #2. Le file descriptor sur lequel ecrire.
** Valeur de retour None
** Fonctions externes autorisees
** write
** Description Écrit l'integer 'n' sur le file descriptor donne.
*/
