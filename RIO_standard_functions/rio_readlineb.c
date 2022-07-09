/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rio_readlineb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 01:58:39 by haryu             #+#    #+#             */
/*   Updated: 2022/07/10 02:42:30 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ryuu_io.h"

static int	check_case(int code, char *bufp, size_t *n, char c)
{
	if (code == 1)
	{
		*bufp++ = c;
		if (c == '\n')
		{
			(*n)++;
			return (TRUE);
		}
		return (FALSE);
	}
	else if (code == 0)
	{
		if (*n == 1)
			return (0);
		else
			return (TRUE);
	}
	else
		return (-1);
}

ssize_t	rio_readlineb(t_rio_t *rp, void *usrbuf, size_t maxlen)
{
	size_t	n;
	int		rc;
	char	c;
	char	*bufp;

	bufp = usrbuf;
	n = 0;
	while (++n < maxlen)
	{
		rc = rio_read(rp, &c, 1);
		if (check_case(rc, bufp, &n, c))
			break ;
		else
		{
			if (rc == 0)
				return (0);
			else if (rc != 1)
				return (-1);
		}
	}
	*bufp = 0;
	return (n - 1);
}

/*
	rc == 1 : normal case, if met '\n' break while state and return.
	rc == 0 : EOF case, if n == 1, no data read if n != 1 some data was read.
	else : Error handling
*/
