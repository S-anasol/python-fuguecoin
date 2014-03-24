import fugue_hash
import weakref
import binascii
import StringIO

from binascii import unhexlify

teststart = '1';
testbin = unhexlify(teststart)
hash_bin = fugue_hash.getPoWHash(testbin)
print hash_bin.encode('hex')