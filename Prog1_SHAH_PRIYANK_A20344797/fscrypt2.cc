#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "openssl/include/openssl/blowfish.h"
#include<math.h>
/* 
implement the encrypt / decrypt function using the openSSL library

1.	void BF_set_key(BF_KEY *key, int len, const unsigned char *data)
2.	void BF_ecb_encrypt(const unsigned char *in, unsigned char *out, BF_KEY *key, unsigned char *ivec, int enc)

implement your own CBC operation mode
*/
const int BLOCKSIZE = 8;

unsigned char *fs_encrypt(void *plaintext, int bufsize, char *keystr, int *resultlen)
{
	
	float s=(bufsize/BLOCKSIZE)+1;
        int temp= (s*BLOCKSIZE)-bufsize+1;
        printf("\n%d=",temp);


        unsigned char *in = (unsigned char *)plaintext;
	unsigned char *ch = (unsigned char *)keystr;
	BF_KEY *key=(BF_KEY *)calloc(1,sizeof(BF_KEY));
	BF_set_key(key, BLOCKSIZE, ch);
	unsigned char* out=(unsigned char*)calloc(bufsize,sizeof(unsigned char));
	
	int i;

	BF_ecb_encrypt(in,out,key,BF_ENCRYPT); 

	printf("Size of out: %ld\n", strlen((char*)out));
	printf("Size of in: %lu\n", strlen((char*)in));
	int templen= sizeof(out);
	
	for(i = 0; i< templen;i++)
	{
		printf("%02x", out[i]);		
	}
	
	return out;

}

void *fs_decrypt(void *ciphertext, int bufsize, char *keystr, int *resultlen)
{

	unsigned char *in = (unsigned char*)ciphertext;
	const unsigned char *ch = (unsigned char*)keystr;	
	BF_KEY *key=(BF_KEY *)calloc(1,sizeof(BF_KEY));
	BF_set_key(key, BLOCKSIZE, ch);
	//unsigned char *out=(unsigned char*)calloc(bufsize,sizeof(unsigned char));
	unsigned char* out=(unsigned char*)calloc(8, sizeof(unsigned char));


	int i = 0;
	printf("ciphertext in decription = %d", sizeof(out));
	
	//BF_ecb_encrypt(in,out,key,BF_DECRYPT);
	//int x = sizeof(out);
	//printf("dsa =%d",x);	
	//for(i=0;i<sizeof(out);i++)
	//{
	//	printf("output: %c",out[i]);
	//}
	
	//printf("Size of out: %ld\n", strlen((char*)out));
}
