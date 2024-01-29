/*
 * SPDX-FileCopyrightText: 1991 - 1994, Julianne Frances Haugh
 * SPDX-FileCopyrightText: 1996 - 2000, Marek Michałkiewicz
 * SPDX-FileCopyrightText: 2002 - 2006, Tomasz Kłoczko
 * SPDX-FileCopyrightText: 2008       , Nicolas François
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _GETDEF_H
#define _GETDEF_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

/* getdef.c */
extern bool getdef_bool (const char *);
extern long getdef_long (const char *, long);
extern int getdef_num (const char *, int);
extern unsigned long getdef_ulong (const char *, unsigned long);
extern unsigned int getdef_unum (const char *, unsigned int);
extern /*@observer@*/ /*@null@*/const char *getdef_str (const char *);
extern int putdef_str (const char *, const char *, const char *);


/* getlong.c */
extern int getlong (const char *numstr, /*@out@*/long int *result);


/* default UMASK value if not specified in /etc/login.defs */
#define		GETDEF_DEFAULT_UMASK	022

#ifdef __cplusplus
}
#endif

#endif				/* _GETDEF_H */
