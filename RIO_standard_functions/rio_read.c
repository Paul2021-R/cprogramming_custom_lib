/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rio_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 01:47:52 by haryu             #+#    #+#             */
/*   Updated: 2022/07/10 02:33:00 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ryuu_io.h"
#include "../42_libft/libft.h"

static ssize_t	copy_internal_usrbuf(size_t n, \
t_rio_t *rp, char *usrbuf)
{
	ssize_t	cnt;

	cnt = n;
	if (rp->rio_cnt < (int)n)
		cnt = rp->rio_cnt;
	ft_memcpy(usrbuf, rp->rio_bufptr, cnt);
	rp->rio_bufptr += cnt;
	rp->rio_cnt -= cnt;
	return (cnt);
}

ssize_t	rio_read(t_rio_t *rp, char *usrbuf, size_t n)
{
	ssize_t	ret;

	while (rp->rio_cnt <= 0)
	{
		rp->rio_cnt = read(rp->rio_fd, rp->rio_buf, sizeof(rp->rio_buf));
		if (rp->rio_cnt < 0)
		{
			if (errno != EINTR)
				return (-1);
		}
		else if (rp->rio_cnt == 0)
			return (0);
		else
			rp->rio_bufptr = rp->rio_buf;
	}
	ret = copy_internal_usrbuf(n, rp, usrbuf);
	return (ret);
}
