#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "openssl/blowfish.h"

/* 
implement the encrypt / decrypt function using the openSSL library

1.	void BF_set_key(BF_KEY *key, int len, const unsigned char *data)
2.	void BF_ecb_encrypt(const unsigned char *in, unsigned char *out, BF_KEY *key, unsigned char *ivec, int enc)

implement your own CBC operation mode
*/
const int BLOCKSIZE = 8;

void *fs_encrypt(void *plaintext, int bufsize, char *keystr, int *resultlen)
{
	// put your code here:
}

void *fs_decrypt(void *ciphertext, int bufsize, char *keystr, int *resultlen)
{
	// put your code here:
}