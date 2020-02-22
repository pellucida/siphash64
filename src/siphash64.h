/*
// @(#) siphash64.h
*/
# if	!defined(SIPHASH64_H)
# define	SIPHASH64_H	1

# include	<stdint.h>
# include	<stdlib.h>

enum	{ // Just to document
	cROUNDS	= 2,
	dROUNDS = 4,
};

// Note: key[2] are two 64 bit numbers in host byte order.
uint64_t	siphash64 (uint8_t* data, size_t len, uint64_t key[2]);

# endif
