#include <string>
#include "CipherInterface.h"
#include "DES.h"
#include "AES.h"

using namespace std;

int main(int argc, char** argv)
{
	/**
	 * TODO: Replace the code below	with your code which can SWITCH
	 * between DES and AES and encrypt files. DO NOT FORGET TO PAD
	 * THE LAST BLOCK IF NECESSARY.
	 *
	 * NOTE: due to the incomplete skeleton, the code may crash or
	 * misbehave.
	 */



	/* Create an instance of the DES cipher */
	CipherInterface* cipher = NULL;
	AES aestest;
	const static unsigned char aes_key[]={0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF};
	unsigned char * x;
	aestest.setKey((unsigned char*)"00123456789abcdef");

	x = aestest.encrypt((unsigned char*)"0123456789abcdef");
	printf("%s\n",x );
	aestest.setKey((unsigned char*)"10123456789abcdef");
	aestest.decrypt(x);


	/* Error checks */
	// if(!cipher)
	// {
	// 	fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
	// 	__FILE__, __FUNCTION__, __LINE__);
	// 	exit(-1);
	// }

	/* Set the encryption key
	 * A valid key comprises 16 hexidecimal
	 * characters. Below is one example.
	 * Your program should take input from
	 * command line.
	 */
	//cipher->setKey((unsigned char*)"0123456789abcdef");

	/* Perform encryption */
	//string cipherText = cipher->encrypt("hello world");

	/* Perform decryption */
	//cipher->decrypt(cipherText);

	return 0;
}
