#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <openssl/blowfish.h>
/* 
implement the encrypt / decrypt function using the openSSL library

1.	void BF_set_key(BF_KEY *key, int len, const unsigned char *data)
2.	void BF_cbc_encrypt(const unsigned char *in, unsigned char *out, long length, BF_KEY *schedule, unsigned char *ivec, int enc)
*/

const int BLOCKSIZE = 8;

unsigned char *fs_encrypt(void *plaintext, int bufsize, char *keystr, int *resultlen)
{
	int i,j;
	unsigned char *input = (unsigned char*)plaintext;
	const unsigned char *ch = (const unsigned char *) &keystr;
    unsigned char *out =  (unsigned char*)calloc(bufsize, sizeof(unsigned char));
	float s=ceil((float)bufsize/BLOCKSIZE);

	printf("\nNumber of char in i/p: %ld\n", strlen((char*)input));
 
	for(j=0;j<strlen((char*)input); j++)
{	
	printf("%c",input[j]);
}

	int Remaining= BLOCKSIZE*s-bufsize+1;
	int lp= BLOCKSIZE*s-bufsize;
	char temp[lp];

	for(i=0; i<=(BLOCKSIZE*s-strlen((char*)input))+2; i=i+1)
	{	
	input[bufsize+i]='5';
	}

    unsigned char ivec[8];
	    for(i=0; i<8; i++) 
	    {
		ivec[i] ='0' ;
	    }

	  BF_KEY *key = (BF_KEY *)calloc(1, sizeof(BF_KEY));
	  BF_set_key(key, BLOCKSIZE, ch );

	  BF_cbc_encrypt(input, out, strlen((char *)input), key, ivec, BF_ENCRYPT);

	  for(i=0; i<strlen((char*)input); i++)
	  {
	   printf("\n cipher text in ecrypt: %02x",*(out+i));
	  }

 *resultlen = strlen((const char*) out);
     return (unsigned char*)out;	
}

unsigned char *fs_decrypt(void *ciphertext, int bufsize, char *keystr, int *resultlen)
{	
	unsigned char *input = (unsigned char*)ciphertext;
	const unsigned char *ch = (const unsigned char *) &keystr;
	int i;
    unsigned char *out =  (unsigned char*)calloc(bufsize, sizeof(unsigned char));
    BF_KEY *key = (BF_KEY *)calloc(1, sizeof(BF_KEY));
    unsigned char ivec[8];
    for(i=0; i<8; i++) 
    {
	ivec[i] = '0';
    }

  BF_set_key(key, BLOCKSIZE, ch );
  BF_cbc_encrypt(input, out, strlen((char *)input), key, ivec, BF_DECRYPT);
  printf("output: %s \n",out);
  *resultlen = strlen((const char*) out+1);
     return (unsigned char*)out;
}

