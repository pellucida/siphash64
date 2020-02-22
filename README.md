# siphash64

64 bit siphash extracted from the reference implementation of SipHash.

[C language reference implementation](https://github.com/veorq/SipHash)

SipHash was designed by [Jean-Philippe Aumasson](https://131002.net) and
[Daniel J. Bernstein](http://cr.yp.to). 

```
## Usage

```
# include	<stdint.h>
# include	<stdlib.h>
# include	"siphash64.h"
uint64_t	siphash64 (uint8_t* data, size_t len, uint64_t keys[2]);
```

## Building

```
cd src
Make
```
produces siphash64.o and siphash64_test which verifies the 64 test vectors
extracted the reference implentation

The code can be adapted to implement SipHash-*c*-*d*, the version of SipHash
with *c* compression rounds and *d* finalization rounds, by redefining the `cROUNDS`
or `dROUNDS` enums in `strhash64.h` before recompiling.  

Obviously, if the number of rounds is modified then the test vectors
won't verify.

## Intellectual property

Exactly as the original authors released the reference implementation.
```
"The SipHash reference code is released under [CC0
license](https://creativecommons.org/publicdomain/zero/1.0/), a public
domain-like licence.

"We aren't aware of any patents or patent applications relevant to
SipHash, and we aren't planning to apply for any.
```

## References

From the reference implementation.
```
The [SipHash page](https://131002.net/siphash) includes
* a list of third-party implementations and modules
* a list of projects using SipHash
* references to cryptanalysis results
```
