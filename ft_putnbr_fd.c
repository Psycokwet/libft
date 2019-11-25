/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/25 16:42:50 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void	ft_putnbr_fd_int(int sign, int n, int fd)
{
	if (n > -10 && n < 10)
		ft_putchar_fd((sign * n) + '0', fd);
	else
	{
		ft_putnbr_fd_int(sign, n / 10, fd);
		ft_putnbr_fd_int(sign, n % 10, fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd(fd, '-');
		ft_putnbr_fd_int(-1, n, fd);
	}
	ft_putnbr_fd_int(1, n, fd);
}
/*
** #1. L’integer à écrire.
** #2. Le file descriptor sur lequel écrire.
** Valeur de retour None
** Fonctions externes autorisées
** write
** Description Écrit l’integer ’n’ sur le file descriptor donné.
*/
