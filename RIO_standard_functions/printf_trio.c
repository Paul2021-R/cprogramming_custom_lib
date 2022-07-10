/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_trio.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 22:33:47 by haryu             #+#    #+#             */
/*   Updated: 2022/07/10 23:00:20 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ryuu_io.h"
#include <stdio.h>

void	printf_trio(t_rio_t *ptr)
{
	printf("1 total size : %lu\n", sizeof(*ptr));
	printf("2 buf : %p(size : %ld)\n", ptr->rio_buf, sizeof( ptr->rio_buf));
	printf("3 bufptr : %p(size : %ld)\n", ptr->rio_bufptr, sizeof( ptr->rio_bufptr));
	printf("5 : FD(size : %d)\n", ptr->rio_fd);
}
