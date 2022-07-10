/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rio_writen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 01:31:37 by haryu             #+#    #+#             */
/*   Updated: 2022/07/10 22:53:43 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ryuu_io.h"

ssize_t	rio_writen(int fd, void *usrbuf, size_t n)
{
	size_t	nleft;
	ssize_t	nwritten;
	char	*bufp;

	nleft = n;
	bufp = usrbuf;
	while (nleft > 0)
	{
		nwritten = write(fd, bufp, nleft);
		{
			if (nwritten <= 0)
			{
				if (errno == EINTR)
					nwritten = 0;
				else
					return (-1);
			}
			nleft -= nwritten;
			bufp += nwritten;
		}
	}
	return (n);
}

/*
	29 : Interrupted by sig handler return.
	30 : and call write() again.
	32 : errno set by write().
*/