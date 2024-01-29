/*
 * SPDX-FileCopyrightText: 2007 - 2009, Nicolas François
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdlib.h>
#include <errno.h>

/*
 * getulong - extract an unsigned long integer provided by the numstr string in *result
 *
 * It supports decimal, hexadecimal or octal representations.
 *
 * Returns 0 on failure, 1 on success.
 */
int getulong (const char *numstr, /*@out@*/unsigned long int *result)
{
	unsigned long int val;
	char *endptr;

	errno = 0;
	val = strtoul (numstr, &endptr, 0);
	if (    ('\0' == *numstr)
	     || ('\0' != *endptr)
	     || (ERANGE == errno)
	   ) {
		return 0;
	}

	*result = val;
	return 1;
}

