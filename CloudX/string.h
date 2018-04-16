/***************************************************************************************************
                                   ByteHub Embedded
****************************************************************************************************
 * File:   string.h
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



/*	String functions */

#ifndef	_STDDEF
typedef	int		ptrdiff_t;	/* result type of pointer difference */
typedef	unsigned	size_t;		/* type yielded by sizeof */
typedef unsigned short	wchar_t;	/* wide char type */
#define	_STDDEF
#define	offsetof(ty, mem)	((int)&(((ty *)0)->mem))
extern int	errno;			/* system error number */

#endif	/* _STDDEF */

#ifndef	NULL
#define	NULL	(0)
#endif

#ifdef _PIC16
extern far void *	memcpy(far void *, const void *, size_t);
extern far void *	memmove(far void *, const void *, size_t);
extern far void *	memset(far void *, int, size_t);
#else  /* _PIC16 */
extern void *	memcpy(void *, const void *, size_t);
extern void *	memmove(void *, const void *, size_t);
extern void *	memset(void *, int, size_t);
#endif /* _PIC16 */

#ifdef _PIC14E
extern void *	__builtin_memcpy(void *, const void *, size_t);
#pragma intrinsic(__builtin_memcpy)
#if defined(__OPTIMIZE_SPEED__) && !defined(_DISABLE_BUILTIN_MEMCPY)
#define memcpy(x,y,z)	__builtin_memcpy(x,y,z)
#endif
#endif
#ifdef _PIC16
extern far char *	strcat(far char *, const char *);
extern far char *	strcpy(far char *, const char *);
extern far char *	strncat(far char *, const char *, size_t);
extern far char *	strncpy(far char *, const char *, size_t);
extern far char *	strdup(const char *);
extern far char *	strtok(far char *, const char *);
#else  /* _PIC16 */
extern char *	strcat(char *, const char *);
extern char *	strcpy(char *, const char *);
extern char *	strncat(char *, const char *, size_t);
extern char *	strncpy(char *, const char *, size_t);
extern char *	strdup(const char *);
extern char *	strtok(char *, const char *);
#endif /* _PIC16 */

extern int	memcmp(const void *, const void *, size_t);
extern int	strcmp(const char *, const char *);
extern int	stricmp(const char *, const char *);
extern int	strncmp(const char *, const char *, size_t);
extern int	strnicmp(const char *, const char *, size_t);
extern  void *	memchr(const void *, int, size_t);
extern size_t	strcspn(const char *, const char *);
extern  char *	strpbrk(const char *, const char *);
extern size_t	strspn(const char *, const char *);
extern  char *	strstr(const char *, const char *);
extern  char *	stristr(const char *, const char *);
extern char *	strerror(int);
extern size_t	strlen(const char *);
extern  char *	strchr(const char *, int);
extern  char *	strichr(const char *, int);
extern  char *	strrchr(const char *, int);
extern  char *	strrichr(const char *, int);

/*
 * C18 string.h equivalents and declarations
 */
#ifdef __18CXX
#define memcmppgm2ram(a,b,c)	memcmp(a,b,c)
#define strcmppgm2ram(a,b)	strcmp(a,b)
#define memcpypgm2ram(a,b,c)	memcpy(a,b,c)
#define strcpypgm2ram(a,b)	strcpy(a,b)
#define strncpypgm2ram(a,b,c)	strncpy(a,b,c)
#define strstrrampgm(a,b)	strstr(a,b)
#define strlenpgm(a)		strlen(a)
#define strchrpgm(a,b)		strchr(a,b)
#define strcatpgm2ram(a,b)	strcat(a,b)
extern char * strupr(char *);
extern char * strlwr(char *);
#endif
