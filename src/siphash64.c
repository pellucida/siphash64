/*
// @(#)	siphash64.c
*/

# include	<stdint.h>
# include	<stdlib.h>

# include	"siphash64.h"

// Note these macros all operate on 64 bit words 
// so no endianess 

// GCC detects this idiom generates rolq or rorq.
# define	ROTL(x, b)	\
 	(((x) << (b)) | ((x) >> (64 - (b))))

#define SIPROUND					\
	do {						\
		v0	+= v1;				\
		v1	= ROTL (v1, 13);		\
		v1	^= v0;				\
		v0	= ROTL (v0, 32);		\
		v2	+= v3;				\
		v3	= ROTL (v3, 16);		\
		v3	^= v2;				\
		v0	+= v3;				\
		v3	= ROTL (v3, 21);		\
		v3	^= v0;				\
		v2	+= v1;				\
		v1	= ROTL (v1, 17);		\
		v1	^= v2;				\
		v2	= ROTL (v2, 32);		\
	} while (0)


uint64_t	siphash64 (uint8_t* data, size_t len, uint64_t key[2]) {
	uint64_t	v0	= 0x736f6d6570736575;
	uint64_t	v1	= 0x646f72616e646f6d;
	uint64_t	v2	= 0x6c7967656e657261;
	uint64_t	v3	= 0x7465646279746573;
	int i;

	uint64_t	key0	= key [0];
	uint64_t	key1	= key [1];
const	uint8_t*	end	= data + len - (len % sizeof(uint64_t));
const	int		left	= len & 7;
	uint64_t	result = ((uint64_t)len) << 56;
	
// keys[] are presented in host byte so order convert to LE
# if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
	key0	= __builtin_bswap64 (key0);
	key1	= __builtin_bswap64 (key1);
# endif

	v3	^= key1;
	v2	^= key0;
	v1	^= key1;
	v0	^= key0;

	for (; data != end; data += sizeof(uint64_t)) {

// This is the only endian bit.
// Assumes the first byte in "data" is the lsb in "m" etc 
//
		uint64_t	m	= *(uint64_t*)(data);

# if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
		m	= __builtin_bswap64 (m);
# endif
		v3	^= m;

		for (i = 0; i < cROUNDS; ++i) {
			SIPROUND;
		}

		v0	^= m;
	}

	switch (left) {
	case 7:
		result	|= ((uint64_t)data[6]) << 48;	// (left-1)*8
	case 6:
		result	|= ((uint64_t)data[5]) << 40;
	case 5:
		result	|= ((uint64_t)data[4]) << 32;
	case 4:
		result	|= ((uint64_t)data[3]) << 24;
	case 3:
		result	|= ((uint64_t)data[2]) << 16;
	case 2:
		result	|= ((uint64_t)data[1]) << 8;
	case 1:
		result	|= ((uint64_t)data[0]);
	break;
	case 0:
	break;
	}

	v3	^= result;

	for (i = 0; i < cROUNDS; ++i) {
		SIPROUND;
	}
	v0	^= result;
	v2	^= 0xff;

	for (i = 0; i < dROUNDS; ++i) {
		SIPROUND;
	}

	result	= v0 ^ v1 ^ v2 ^ v3;
	return result;
}
