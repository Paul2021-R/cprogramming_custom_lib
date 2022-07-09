/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   STDIN_and_STDOUT.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 01:38:59 by haryu             #+#    #+#             */
/*   Updated: 2022/07/10 02:52:29 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ryuu_io.h"
#include <stdio.h>

#define MAXLINE RIO_BUFSIZE

int	main(int argc, char **argv)
{
	int		n;
	t_rio_t	rio;
	char	buf[MAXLINE];

	rio_readinitb(&rio, STDIN_FILENO);
	n = rio_readlineb(&rio, buf, MAXLINE);
	while (n != 0)
	{
		rio_writen(STDOUT_FILENO, buf, n);
		n = rio_readlineb(&rio, buf, MAXLINE);
	}
	return (0);
}
