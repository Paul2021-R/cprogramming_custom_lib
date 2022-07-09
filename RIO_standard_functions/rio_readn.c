/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rio_readn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 01:27:28 by haryu             #+#    #+#             */
/*   Updated: 2022/07/10 02:56:53 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ryuu_io.h"
#include <stdio.h>

ssize_t	rio_readn(int fd, void *usrbuf, size_t n)
{
	size_t		nleft;
	ssize_t		nread;
	char		*bufp;

	nleft = n;
	bufp = usrbuf;
	while (nleft > 0)
	{
		nread = read(fd, bufp, nleft);
		if (nread < 0)
		{
			if (errno == EINTR)
				nread = 0;
			else
				return (-1);
		}
		else if (nread == 0)
			break ;
		nleft -= nread;
		bufp += nread;
	}
	return (n - nleft);
}

/*
	16 : Interrputed by sig handler return 
	17 : and call read() again
	19 : errno set by read()
	22 : case of EOF break and return 
	26 : return >= 0
*/
