/***************************************************************************************************
                                   ByteHub Embedded
****************************************************************************************************
 * File:   stdlib.h
 * Version: 1.0
 * Author: Ayinde Olayiwola
 * Website: http://www.makeelectronics.ng or http://www.bytehubembedd.com
 * Description: This file contains the program to demonstrate the LED blinking. 

This code has been developed and tested on CloudX microcontroller boards.  
We strongly believe that the library works on any of development boards for respective controllers. 
Check this link http://www.makeelectronics.ng for awesome tutorials on CloudX,ARM,Robotics,RTOS,IOT.
ByteHub Embedded invests substantial time and effort developing open source HW and SW tools,
to support consider buying the CloudX microcontroller boards.
 
The ByteHub Embedded libraries and examples are licensed under the terms of the new-bsd license
(two-clause bsd license). See also: http://www.opensource.org/licenses/bsd-license.php

BYTEHUB EMEBEDED DISCLAIMS ANY KIND OF HARDWARE FAILURE RESULTING OUT OF USAGE OF LIBRARIES, DIRECTLY OR
INDIRECTLY. FILES MAY BE SUBJECT TO CHANGE WITHOUT PRIOR NOTICE. THE REVISION HISTORY CONTAINS THE 
INFORMATION RELATED TO UPDATES.
 

Permission to use, copy, modify, and distribute this software and its documentation for any purpose
and without fee is hereby granted, provided that this copyright notices appear in all copies 
and that both those copyright notices and this permission notice appear in supporting documentation.
**************************************************************************************************/



/*	Standard utility functions */

#ifndef	_STDDEF
typedef	int		ptrdiff_t;	/* result type of pointer difference */
typedef	unsigned	size_t;		/* type yielded by sizeof */
typedef unsigned short	wchar_t;	/* wide char type */

#define	offsetof(ty, mem)	((int)&(((ty *)0)->mem))

#define	_STDDEF

#ifndef	NULL
#define	NULL	(0)
#endif

extern int	errno;			/* system error number */
#endif	/* _STDDEF */

#ifndef	_STDLIB_
#define	_STDLIB_
#define	RAND_MAX	32767		/* max value returned by rand() */
#define	EXIT_SUCCESS	0
#define	EXIT_FAILURE	1

#ifndef	_DIVTYPES
#if	(defined(_MPC_) && !defined(__DSPICC__)) || defined(i8051) || defined(__18CXX)
typedef struct {
	int	rem;	/* remainder */		/* PIC version returns remainder here */
	int	quot;	/* quotient */
} div_t;				/* div() return type */
typedef struct {
	unsigned	rem;	/* remainder */		/* PIC version returns remainder here */
	unsigned	quot;	/* quotient */
} udiv_t;				/* div() return type */
typedef struct {
	long 	quot;	/* quotient */
	long 	rem;	/* remainder */
} ldiv_t;				/* ldiv() return type */
typedef struct {
	unsigned long 	quot;	/* quotient */
	unsigned long 	rem;	/* remainder */
} uldiv_t;				/* ldiv() return type */
#else
typedef struct {
	int	quot;	/* quotient */
	int	rem;	/* remainder */
} div_t;				/* div() return type */
typedef struct {
	unsigned	quot;	/* quotient */
	unsigned	rem;	/* remainder */
} udiv_t;				/* div() return type */
typedef struct {
	long 	quot;	/* quotient */
	long 	rem;	/* remainder */
} ldiv_t;				/* ldiv() return type */
typedef struct {
	unsigned long 	quot;	/* quotient */
	unsigned long 	rem;	/* remainder */
} uldiv_t;				/* ldiv() return type */
#endif	/* _MPC_ */

#define	_DIVTYPES
#endif

extern double		atof(const char *);
extern double		strtod(const char *, const char **);
extern int			atoi(const char *);
extern unsigned		xtoi(const char *);
extern long			atol(const char *);
extern long			strtol(const char *, char **, int);
#define	strtoul(a,b,c)	((unsigned long)strtol((a),(b),(c)))
extern int			rand(void);
extern void			srand(unsigned int);
extern void *		calloc(size_t, size_t);
extern div_t		div(int numer, int denom);
extern udiv_t		udiv(unsigned numer, unsigned denom);
extern ldiv_t		ldiv(long numer, long denom);
extern uldiv_t		uldiv(unsigned long numer,unsigned  long denom);
extern unsigned long	_lrotl(unsigned long value, unsigned int shift);
extern unsigned long	_lrotr(unsigned long value, unsigned int shift);
extern unsigned int	_rotl(unsigned int value, unsigned int shift);
extern unsigned int	_rotr(unsigned int value, unsigned int shift);

#define	max(a,b)	(((a) > (b)) ? (a) : (b))
#define	min(a,b)	(((a) < (b)) ? (a) : (b))

extern void *		malloc(size_t);
extern void		free(void *);
extern void *		realloc(void *, size_t);

extern void	abort(void);
extern void	exit(int);
extern int	atexit(void (*)(void));
extern char *	getenv(const char *);
extern char **	environ;
extern int	system(char *);
extern void	qsort(void *, size_t, size_t, int (*)(const void *, const void *));
extern void *	bsearch(const void *, void *, size_t, size_t, int(*)(const void *, const void *));
extern int	abs(int);
extern long	labs(long);
#endif

extern char *	itoa(char * buf, int val, int base);
extern char *	utoa(char * buf, unsigned val, int base);
#ifdef __18CXX
extern char *	ltoa(long val, char * buf);
extern char *	ultoa(unsigned long val, char * buf);
#else
extern char *	ltoa(char * buf, long val, int base);
extern char *	ultoa(char * buf, unsigned long val, int base);
#endif
extern char *	ftoa(float f, int * status);

#ifdef __18CXX
#define atob(a)		((signed char)atoi(a))
#define atoul(a)	((unsigned long)atol(a))
#define btoa(a,b)	itoa((signed char)(a),b)
#endif
