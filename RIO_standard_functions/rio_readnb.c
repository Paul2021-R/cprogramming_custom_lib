/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rio_readnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 02:21:45 by haryu             #+#    #+#             */
/*   Updated: 2022/07/10 02:24:00 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ryuu_io.h"

ssize_t	rio_readnb(t_rio_t *rp, void *usrbuf, size_t n)
{
	size_t	nleft;
	ssize_t	nread;
	char	*bufp;

	nleft = n;
	bufp = usrbuf;
	while (nleft > 0)
	{
		nread = rio_read(rp, bufp, nleft);
		if (nread < 0)
			return (-1);
		else if (nread == 0)
			break ;
		nleft -= nread;
		bufp += nread;
	}
	return (n - nleft);
}
