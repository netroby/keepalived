/*
 * Soft:        Perform a GET query to a remote HTTP/HTTPS server.
 *              Set a timer to compute global remote server response
 *              time.
 *
 * Part:        sock.c include file.
 *
 * Version:     $Id: sock.h,v 1.0.0 2002/11/20 21:34:18 acassen Exp $
 *
 * Authors:     Alexandre Cassen, <acassen@linux-vs.org>
 *
 *              This program is distributed in the hope that it will be useful,
 *              but WITHOUT ANY WARRANTY; without even the implied warranty of
 *              MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *              See the GNU General Public License for more details.
 *
 *              This program is free software; you can redistribute it and/or
 *              modify it under the terms of the GNU General Public License
 *              as published by the Free Software Foundation; either version
 *              2 of the License, or (at your option) any later version.
 */

#ifndef _SOCK_H
#define _SOCK_H

/* system includes */
#include <openssl/ssl.h>
#include <openssl/md5.h>

/* Engine socket pool element structure */
typedef struct {
	int fd;
	SSL *ssl;
	BIO *bio;
	MD5_CTX context;
	int status;
	int lock;
	char *buffer;
	char *extracted;
	int size;
	int total_size;
} SOCK;

/* Prototypes */
extern void free_sock(SOCK *sock);
extern void init_sock(void);

#endif