/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ryuu_io.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 01:01:39 by haryu             #+#    #+#             */
/*   Updated: 2022/07/10 22:48:56 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RYUU_IO_H
# define RYUU_IO_H

/* RYUU_IO_H */
/* These are devlepped for reliable IO features. */
/* These are based on */
/* "Computer Systems A Programmer's Perspective 3rd edtion" guided. */

# include <unistd.h>
# include <errno.h>
# include <stdio.h>

# define RIO_BUFSIZE 		8192
# define TRUE				1
# define FALSE				0

/**
 * @brief rio_t for rio_readlinetb functions
 * rio_fd		Descriptror for this internal buf
 * rio_cnt		Unread bytes in internal buf
 * rio_bufptr	Next unread byte in internal buf
 * rio_buf		Internal buffer
 */
typedef struct s_rio_t
{
	int		rio_fd;
	int		rio_cnt;
	char	*rio_bufptr;
	char	rio_buf[RIO_BUFSIZE];
}					t_rio_t;

ssize_t		rio_read(t_rio_t *rp, char *usrbuf, size_t n);

/**
 * @brief handling signal and read n bytes application requested.
 * 
 * @param fd		: file descriptor
 * @param usrbuf 	: use user's buffer to transfer data to memory
 * @param n 		: the target size to read from a file.
 * @return ssize_t 
 */
ssize_t		rio_readn(int fd, void *usrbuf, size_t n);

/**
 * @brief initialize t_rio_t structure data set.
 * 
 * @param rp		: new data set.
 * @param fd 		: target file fd.
 */
void		rio_readinitb(t_rio_t *rp, int fd);

/**
 * @brief 
 * 
 * @param rp 
 * @param usrbuf 
 * @param maxlen 
 * @return ssize_t 
 */
ssize_t		rio_readlineb(t_rio_t *rp, void *usrbuf, size_t maxlen);

/**
 * @brief 
 * 
 * @param rp 
 * @param usrbuf 
 * @param n 
 * @return ssize_t 
 */
ssize_t		rio_readnb(t_rio_t *rp, void *usrbuf, size_t n);

/**
 * @brief 
 * 
 * @param fd 
 * @param usrbuf 
 * @param n 
 * @return ssize_t 
 */
ssize_t		rio_writen(int fd, void *usrbuf, size_t n);

/**
 * @brief 
 * 
 * @param byte 
 * @param error_handler 
 * @return void* 
 */
void		*ft_malloc_wrapper(size_t byte, char *error_handler);
void		printf_trio(t_rio_t *ptr);

#endif 
