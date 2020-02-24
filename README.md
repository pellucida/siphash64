## siphash64

Simplified interface to 64 bit only version of siphash extracted from
the reference implementation of _SipHash_.

C language reference implementation (https://github.com/veorq/SipHash)

_SipHash_ was designed by [Jean-Philippe Aumasson](https://131002.net) and
[Daniel J. Bernstein](http://cr.yp.to). 

## Usage

```
# include	<stdint.h>
# include	<stdlib.h>
# include	"siphash64.h"
uint64_t	siphash64 (uint8_t* data, size_t len, uint64_t keys[2]);
```
### Example
```
  char  data []   = "An example string to hash";
  uint64_t  keys[2]  = {  0xa0b0c0d0e0f09080, 0xabaddeadbeefcafe };
  uint64_t  hash  = siphash64 (data, sizeof(data)-1, keys);
  printf ("0x%lx\n", hash);
  
  0xd52650118133d393
```


## Building

```
cd src
Make
```

produces _siphash64.o_ and _siphash64_test_ which verifies the 64 test vectors
extracted the reference implentation

The code can be adapted to implement _SipHash-*c*-*d*_, the version of SipHash
with *c* compression rounds and *d* finalization rounds, by redefining the __cROUNDS__
or __dROUNDS__ enums in _strhash64.h_ before recompiling.  

Obviously, if the number of rounds is modified then the test vectors
won't verify.

## Intellectual property

Exactly the same as when the original authors released the reference implementation.

```
"The SipHash reference code is released under
[CC0 license](https://creativecommons.org/publicdomain/zero/1.0/),
a public domain-like licence.

"We aren't aware of any patents or patent applications relevant to
SipHash, and we aren't planning to apply for any.
```
## License

See above 
[CC0 license](https://creativecommons.org/publicdomain/zero/1.0/)

## References

From the reference implementation.
```
The [SipHash page](https://131002.net/siphash) includes
* a list of third-party implementations and modules
* a list of projects using SipHash
* references to cryptanalysis results
```
